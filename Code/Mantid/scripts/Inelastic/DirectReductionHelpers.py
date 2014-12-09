from mantid import config

"""
Set of functions to assist with processing instrument parameters relevant to reduction. 
"""
class ComplexProperty(object):
    """ Class describes property which depends on other properties and stores/receives values in other properties """ 
    def __init__(self,other_prop_list):
        self._other_prop = other_prop_list;
 
    def __get__(self,spec_dict,owner=None):
        """ return complex properties list """
        rez = list();
        for key in self._other_prop:
            rez.append(spec_dict[key]);
        return rez;
    def __set__(self,spec_dict,value):
        if len(value) != len(self._other_prop):
            raise KeyError("Complex property values can be set equal to the same length values list");
        
        changed_prop=[];
        for i,key in enumerate(self._other_prop):
                spec_dict[key] =value[i];
                changed_prop.append(key);
        return changed_prop;

    def len(self):
        return len(self._other_prop);
#end ComplexProperty



def get_default_parameter(instrument, name):
        """ Function gets the value of a default instrument parameter and 
            assign proper(the one defined in IPF ) type to this parameter 
            @param instrument -- 
        """ 

        if instrument is None:
            raise ValueError("Cannot initiate default parameter, instrument has not been properly defined.")

        type_name = instrument.getParameterType(name)
        if type_name == "double":
            val = instrument.getNumberParameter(name)
        elif type_name == "bool":
            val = instrument.getBoolParameter(name)
        elif type_name == "string":
            val = instrument.getStringParameter(name)
            if val[0] == "None" :
                return None
        elif type_name == "int" :
              val = instrument.getIntParameter(name)
        else :
            raise KeyError(" Instrument: {0} does not have parameter with name: {1}".format(instrument.getName(),name))

        return val[0]

def get_default_idf_param_list(pInstrument,synonims_list=None):
    """ Obtain default reduction parameters list from the instrument """

    params = pInstrument.getParameterNames();
    par_list = {};
    for name in params:
        par_list[name] = get_default_parameter(pInstrument,name);


    return par_list;



def build_properties_dict(param_map,synonims,preffix='') :
    """ function builds the properties list from the properties strings obtained from Insturment_Parameters.xml file
              
       The properties, which have simple values are added to dictionary in the form:
       properties_dict[prop_name]=(False,value);

       The properties, expressed trough the values of other properties 
       e.g. strings in a form key1 = key2:key3  
       are added to the dictionary in the form:
       in the form properties_dict[key1]=(True,['key2','key3'])

    """ 
    # dictionary used for substituting composite keys.
    prelim_dict = dict();

    for name in param_map:
       if name in synonims:
          final_name = preffix+str(synonims[name]);
       else:
          final_name = preffix+str(name)
       prelim_dict[final_name]=None;

    param_keys = prelim_dict.keys();
    properties_dict = dict();

    for name,val in param_map.items() :
        if name in synonims:
            final_name = preffix+str(synonims[name]);
        else:
            final_name = preffix+str(name)

        if isinstance(val,str):  
               val = val.strip()
               keys_candidates = val.split(":")
               n_keys = len(keys_candidates)
               #
               if n_keys>1 : # this is the property we want to modify
                   result=list();
                   for key in keys_candidates :
                       if key in synonims:
                           rkey = preffix+str(synonims[key]);
                       else:
                           rkey = preffix+str(key);
                       if rkey in param_keys:
                          result.append(rkey);
                       else:
                          raise KeyError('Substitution key : {0} is not in the list of allowed keys'.format(rkey));
                   properties_dict['_'+final_name]=ComplexProperty(result)
               else:
                   properties_dict[final_name] =keys_candidates[0];
        else:
            properties_dict[final_name]=val;

    return properties_dict


def extract_non_system_names(names_list,prefix='__'):
    """ The function processes the input list and returns 
        the list with names which do not have the system framing (leading __)                  
    """
    result = list();
    ns = len(prefix);
    for name in names_list:
        pend = min(ns,len(name))
        if name[:pend] != prefix:
            result.append(name)
    return result

def build_subst_dictionary(synonims_list=None) :
    """Function to process "synonims_list" in the instrument parameters string, used to support synonyms in the reduction script

       it takes string of synonyms in the form key1=subs1=subst2=subts3;key2=subst4 and returns the dictionary
       in the form dict[subs1]=key1 ; dict[subst2] = key1 ... dict[subst4]=key2

       e.g. if one wants to use the IDF key word my_detector instead of e.g. norm-mon1-spec, he has to type
       norm-mon1-spec=my_detector in the synonyms field of the IDF parameters file.
    """
    if not synonims_list :  # nothing to do
            return dict();
    if type(synonims_list) == dict : # all done
            return synonims_list
    if type(synonims_list) != str :
            raise AttributeError("The synonyms field of Reducer object has to be special format string or the dictionary")
        # we are in the right place and going to transform string into dictionary

    subst_lines = synonims_list.split(";")
    rez  = dict()
    for lin in subst_lines :
        lin=lin.strip()
        keys = lin.split("=")
        if len(keys) < 2 :
                raise AttributeError("The pairs in the synonyms fields have to have form key1=key2=key3 with at least two values present")
        if len(keys[0]) == 0:
                raise AttributeError("The pairs in the synonyms fields have to have form key1=key2=key3 with at least two values present, but the first key is empty")
        for i in xrange(1,len(keys)) :
                if len(keys[i]) == 0 :
                    raise AttributeError("The pairs in the synonyms fields have to have form key1=key2=key3 with at least two values present, but the key"+str(i)+" is empty")
                kkk = keys[i].strip();
                rez[kkk]=keys[0].strip()

    return rez;

def gen_getter(keyval_dict,key):
    """ function returns value from dictionary with substitution 
    
        e.g. if keyval_dict[A] = 10, keyval_dict[B] = 20 and key_val[C] = [A,B]
        gen_getter(keyval_dict,A) == 10;  gen_getter(keyval_dict,B) == 20;
        and gen_getter(keyval_dict,C) == [10,20];
    """
    if not(key in keyval_dict):
        name = '_'+key
        if not(name in keyval_dict):
            raise KeyError('Property with name: {0} is not among the class properties '.format(key));
    else:
        name = key

    a_val= keyval_dict[name];
    if isinstance(a_val,ComplexProperty):
        return a_val.__get__(keyval_dict);
    else:
        return a_val


    #end
#end



def gen_setter(keyval_dict,key,val):
    """ function sets value to dictionary with substitution 
    
        e.g. if keyval_dict[A] = 10, keyval_dict[B] = 20 and key_val[C] = [A,B]

        gen_setter(keyval_dict,A,20)  causes keyval_dict[A] == 20
        gen_setter(keyval_dict,B,30)  causes keyval_dict[B] == 30
        and gen_getter(keyval_dict,C,[1,2]) causes keyval_dict[A] == 1 and keyval_dict[B] == 2
    """

    if not(key in keyval_dict):
        name = '_'+key
        if not(name in keyval_dict):
            raise KeyError(' Property name: {0} is not defined'.format(key))
    else:
        name = key

    test_val = keyval_dict[name];
    if isinstance(test_val,ComplexProperty):
       if not isinstance(val,list):
          raise KeyError(' You can not assign non-list value to complex property {0}'.format(key))
       pass
            # Assigning values for composite function to the function components
       return test_val.__set__(keyval_dict,val)
    else:
       keyval_dict[key] = val;
    return None


def check_instrument_name(old_name,new_name):
    """ function checks if new instrument name is acceptable instrument name"""


    if new_name is None:
       if not(old_name is None):
            return (None,None,str(config.getFacility()))
       else:
            raise KeyError("No instrument name is defined")

    if old_name == new_name:
       return;

    # Instrument name might be a prefix, query Mantid for the full name
    short_name=''
    full_name=''
    try :
        instrument = config.getFacility().instrument(new_name)
        short_name = instrument.shortName()
        full_name = instrument.name()
    except RuntimeError:
        # it is possible to have wrong facility:
        facilities = config.getFacilities()
        old_facility = str(config.getFacility())
        for facility in facilities:
               config.setString('default.facility',facility.name())
               try :
                   instrument = facility.instrument(new_name)
                   short_name = instrument.shortName()
                   full_name = instrument.name()
                   if len(short_name)>0 :
                       break
               except:
                   pass
        if len(short_name)==0 :
           config.setString('default.facility',old_facility)
           raise KeyError(" Can not find/set-up the instrument: "+new_name+' in any supported facility')

    new_name = short_name
    facility = str(config.getFacility())

    config['default.instrument'] = full_name
    return (new_name,full_name,facility);



       #if not hasattr(self,'instrument') or self.instrument.getName() != instr_name :
       #     # Load an empty instrument if one isn't already there
       #     idf_dir = config.getString('instrumentDefinition.directory')
       #     try:
       #         idf_file=api.ExperimentInfo.getInstrumentFilename(new_name)
       #         tmp_ws_name = '__empty_' + new_name
       #         if not mtd.doesExist(tmp_ws_name):
       #             LoadEmptyInstrument(Filename=idf_file,OutputWorkspace=tmp_ws_name)
       #         self.instrument = mtd[tmp_ws_name].getInstrument()
       #     except:
       #         self.instrument = None
       #         self._instr_name = None
       #         raise RuntimeError('Cannot load instrument for prefix "%s"' % new_name)

