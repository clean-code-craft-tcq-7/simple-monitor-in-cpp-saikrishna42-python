#ifndef _LANGUAGE_SUPPORT_HPP
#define _LANGUAGE_SUPPORT_HPP

    #if(Lang_support==Lang_Support_English)
        #include "English_Lang_EarlyWarn_support.hpp"
    #elif(Lang_support==Lang_Support_Germany)
        #include "German_Lang_EarlyWarn_support.hpp"
    #endif

#endif