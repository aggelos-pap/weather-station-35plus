 /****************************************************************************************************/
 /* Returns temperature in DegC, resolution is 0.01 DegC. Output value of “5123” equals 51.23 DegC.  */
 /***************************************************************************************************/
 
 static long BME280_Compensate_T() {
   long temp1, temp2, T;
 
  temp1 = ((((adc_T>>3) -((long)cal_param.dig_T1<<1))) * ((long)cal_param.dig_T2)) >> 11;
   temp2 = (((((adc_T>>4) - ((long)cal_param.dig_T1)) * ((adc_T>>4) - ((long)cal_param.dig_T1))) >> 12) * ((long)cal_param.dig_T3)) >> 14;
   t_fine = temp1 + temp2;
   T = (t_fine * 5 + 128) >> 8;
   return T;
 }
 
 /************************************************************************************************************/
 /* Returns humidity in %RH as unsigned 32 bit integer in Q22.10 format (22 integer and 10 fractional bits). */
 /* Output value of “47445” represents 47445/1024 = 46.333 %RH */
 /************************************************************************************************************/

 static unsigned long BME280_Compensate_H() {
   long h1;
   h1 = (t_fine - ((long)76800));
   h1 = (((((adc_H << 14) - (((long)cal_param.dig_H4) << 20) - (((long)cal_param.dig_H5) * h1)) +
     ((long)16384)) >> 15) * (((((((h1 * ((long)cal_param.dig_H6)) >> 10) * (((h1 *
     ((long)cal_param.dig_H3)) >> 11) + ((long)32768))) >> 10) + ((long)2097152)) *
     ((long)cal_param.dig_H2) + 8192) >> 14));
   h1 = (h1 - (((((h1 >> 15) * (h1 >> 15)) >> 7) * ((long)cal_param.dig_H1)) >> 4));
   h1 = (h1 < 0 ? 0 : h1);
   h1 = (h1 > 419430400 ? 419430400 : h1);
   return (unsigned long)(h1>>12);
 }