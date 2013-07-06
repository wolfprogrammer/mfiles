

function awg= AWG( awgnumber) 
%   awg= AWG( awgnumber) 
%
%  Retorna os seguintes parâmetros para um dado número AWG: American Wire Gauge
%
%  Entrada número AWG : awgnumber  ( ** Se AWG=-1 ) retorna a tabela completa
%
%  Saída
% [ AWG       Dia-mils  TPI       Dia-mm    Circ-mils Ohms/Kft  Ft/Ohm    Ft/Lb     Ohms/Lb   Lb/Kft    *Amps     MaxAmps ]
%  
%  em uma matriz exemplo   Dia-mm= awg(3)
%
%  
%
%---------------------------------------------------------------------------------------------------------------------------
%   Fonte:  http://amasci.com/tesla/wire1.txt
%
%
%       AWG AMERICAN WIRE GAUGE TABLE FOR BARE COPPER WIRE
%{
Compiled by Fr. Thomas McGahee tom_mcgahee@sigmais.com

This Table may be copied freely so long as credit is given to the author.
Originally compiled for use by those building Tesla coils on the TESLA and
TESLA-2 internet mailing lists.

Compiled in April 1998 based on information derived from various sources.
Since there were some discrepancies between data sources, the author has chosen
not to just copy the numbers found in those sources, but rather to write a
program that would generate the data based on a Best Fit mathematical model.
The author has checked the Diameter in mils results against the data contained in the
MACHINERY'S HANDBOOK, Twenty-First Edition, 1982, published by Industrial Press Inc.
All numbers shown are accurate to +/- 1 in the least significant digit position.
Column headings have been repeated to make the list more readable

AWG = American Wire Gauge size from 0000 to 40
Dia-mils = Diameter in mils (1 mil = .001 inch)
TPI = Turns Per Inch [Note that this is for BARE WIRE. Insulation thickness varies]
Dia-mm = Diameter in millimeters. This was included to help when dealing with metric Coilers.
Circ-mils = Cross sectional Area in Circular Mils. ( circular mils = diameter in mils squared )
Ohms/Kft = Ohms Per 1,000 ft.
Ft/Ohm = Number of feet required for 1 Ohm of resistance
Ft/Lb = Feet Per Pound
Ohms/Lb = Ohms Per Pound
Lb/Kft = Pounds Per 1,000 feet
*AMPS = Conservative Amp Rating based on 750 circulare mils per Amp
MaxAmps = Maximum allowable current based on 500 circular mils per Amp. Do NOT exceed this rating.
%}


%   AWG       Dia-mils  TPI       Dia-mm    Circ-mils Ohms/Kft  Ft/Ohm    Ft/Lb     Ohms/Lb   Lb/Kft    *Amps     MaxAmps 
awgtable = [
 0         324.85    3.0783    8.2513    105531    0.0983     10175    3.1305    0.0003    319.44    140.71    211.06
 1         289.29    3.4567    7.3480     83690    0.1239    8069.5    3.9475    0.0005    253.33    111.59    167.38
 2         257.62    3.8817    6.5436     66369    0.1563    6399.4    4.9777    0.0008    200.90    88.492    132.74
 3         229.42    4.3588    5.8272     52633    0.1970    5075.0    6.2767    0.0012    159.32    70.177    105.27
 4         204.30    4.8947    5.1893     41740    0.2485    4024.7    7.9148    0.0020    126.35    55.653    83.480
 5         181.94    5.4964    4.6212     33101    0.3133    3191.7    9.9804    0.0031    100.20    44.135    66.203
 6         162.02    6.1721    4.1153     26251    0.3951    2531.1    12.585    0.0050    79.460    35.001    52.501
 7         144.28    6.9308    3.6648     20818    0.4982    2007.3    15.869    0.0079    63.014    27.757    41.635
 8         128.49    7.7828    3.2636     16509    0.6282    1591.8    20.011    0.0126    49.973    22.012    33.018
 9         114.42    8.7396    2.9063     13092    0.7921    1262.4    25.233    0.0200    39.630    17.456    26.185
10         101.90    9.8140    2.5881     10383    0.9989    1001.1    31.819    0.0318    31.428    13.844    20.765
11         90.741    11.020    2.3048    8233.9    1.2596    793.93    40.122    0.0505    24.924    10.978    16.468
12         80.807    12.375    2.0525    6529.8    1.5883    629.61    50.593    0.0804    19.765    8.7064    13.060
13         71.961    13.896    1.8278    5178.3    2.0028    499.31    63.797    0.1278    15.675    6.9045    10.357
14         64.083    15.605    1.6277    4106.6    2.5255    395.97    80.447    0.2031    12.431    5.4755    8.2132
15         57.067    17.523    1.4495    3256.7    3.1845    314.02    101.44    0.3230    9.8579    4.3423    6.5134
16         50.820    19.677    1.2908    2582.7    4.0156    249.03    127.91    0.5136    7.8177    3.4436    5.1654
17         45.257    22.096    1.1495    2048.2    5.0636    197.49    161.30    0.8167    6.1997    2.7309    4.0963
18         40.302    24.813    1.0237    1624.3    6.3851    156.62    203.39    1.2986    4.9166    2.1657    3.2485
19         35.890    27.863    0.9116    1288.1    8.0514    124.20    256.47    2.0648    3.8991    1.7175    2.5762
20         31.961    31.288    0.8118    1021.5    10.153    98.496    323.41    3.2832    3.0921    1.3620    2.0430
21         28.462    35.134    0.7229    810.10    12.802    78.111    407.81    5.2205    2.4521    1.0801    1.6202
22         25.346    39.453    0.6438    642.44    16.143    61.945    514.23    8.3009    1.9446    0.8566    1.2849
23         22.572    44.304    0.5733    509.48    20.356    49.125    648.44    13.199    1.5422    0.6793    1.0190
24         20.101    49.750    0.5106    404.03    25.669    38.958    817.66    20.987    1.2230    0.5387    0.8081
25         17.900    55.866    0.4547    320.41    32.368    30.895    1031.1    33.371    0.9699    0.4272    0.6408
26         15.940    62.733    0.4049    254.10    40.815    24.501    1300.1    53.061    0.7692    0.3388    0.5082
27         14.195    70.445    0.3606    201.51    51.467    19.430    1639.4    84.371    0.6100    0.2687    0.4030
28         12.641    79.105    0.3211    159.80    64.898    15.409    2067.3    134.15    0.4837    0.2131    0.3196
29         11.257    88.830    0.2859    126.73    81.835    12.220    2606.8    213.31    0.3836    0.1690    0.2535 
30         10.025    99.750    0.2546    100.50    103.19    9.6906    3287.1    339.18    0.3042    0.1340    0.2010
31         8.9276    112.01    0.2268    79.702    130.12    7.6850    4145.0    539.32    0.2413    0.1063    0.1594
32         7.9503    125.78    0.2019    63.207    164.08    6.0945    5226.7    857.55    0.1913    0.0843    0.1264
33         7.0799    141.24    0.1798    50.125    206.90    4.8332    6590.8    1363.6    0.1517    0.0668    0.1003
34         6.3048    158.61    0.1601    39.751    260.90    3.8329    8310.8    2168.1    0.1203    0.0530    0.0795
35         5.6146    178.11    0.1426    31.524    328.99    3.0396     10480    3447.5    0.0954    0.0420    0.0630
36         5.0000    200.00    0.1270    25.000    414.85    2.4105     13215    5481.7    0.0757    0.0333    0.0500
37         4.4526    224.59    0.1131    19.826    523.11    1.9116     16663    8716.2    0.0600    0.0264    0.0397
38         3.9652    252.20    0.1007    15.723    659.63    1.5160     21012     13859    0.0476    0.0210    0.0314
39         3.5311    283.20    0.0897    12.469    831.78    1.2022     26496     22037    0.0377    0.0166    0.0249
40         3.1445    318.01    0.0799    9.8880    1048.9    0.9534     33410     35040    0.0299    0.0132    0.0198
];
%keyboard;

if(awgnumber==-1) 
	awg=awgtable;
else
	awg=awgtable(awgnumber+1,:);
end




