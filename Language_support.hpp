#ifndef _LANGUAGE_SUPPORT_HPP_
#define _LANGUAGE_SUPPORT_HPP_

#include "Project_Config.hpp"


#if(Lang_support==Lang_Support_English)
   #define temp_out_rang_msg "Temperature out of range!\n"
   #define soc_out_rang_msg "State of Charge out of range!\n"
   #define chargeRate_out_rang_msg "Charge Rate out of range!\n"
#elif(Lang_support==Lang_Support_Germany)
   #define temp_out_rang_msg "Temperatur außerhalb des Bereichs!\n"
   #define soc_out_rang_msg "Ladezustand außerhalb des Bereichs!\n"
   #define chargeRate_out_rang_msg "Laderate außerhalb des Bereichs!\n"
#else
{

}
#endif

#endif

