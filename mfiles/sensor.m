function  SENSOR=sensor(InputRange,SensorRange,CountsRange=[0,1024],units=["V" "rpm"])
%
%   InputRange:  Voltage Value/Current Value
%   SensorRange: Measurement range
%   CountsRange: Analog Card counting
%   Units
SENSOR.InputRange=InputRange      ;
SENSOR.SensorRange=SensorRange    ;
SENSOR.CountsRange=CountsRange    ;
#SENSOR.InUnit=units[0]            ;
#SENSOR.OutUnit=units[1]           ; 

