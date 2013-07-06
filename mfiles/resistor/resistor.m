%	Resistor calculator
%
%

MEGA=1e6;



%-------------  GENERATE THE RE12 TABLE -------------------%
%
%


	% *******  Resistor serie E12 10%  *********** %

E12MAX= 1*MEGA;
RE12_ = [ 10 12 15 18 22 27 33 39 47 56 68 82 ];
RE12= [];


for k=-1:6
	RE12 = [RE12 RE12_.*10^k ] ;
endfor

RE12=RE12(RE12<= E12MAX);
RE12=RE12';

	% *******  Resistor serie E24 5% *********** %

E24MAX= 1*MEGA;
RE24_ = [ 1 11 12 13 15 16 18 20 22 24 27 30 33 36 39 43 47 51 56 62 68 75 82 91 ];
RE24= [];


for k=-1:6
	RE24 = [RE24 RE24_.*10^k ] ;
endfor

RE24=RE24(RE24<= E24MAX);
RE24=RE24'; 



	% *******  Resistor serie E96 1% (precision)  *********** %
E96MAX= 1*MEGA;
RE96_= [ 1.00 1.02 1.05 1.07 1.10 1.13 1.15 1.18 1.21 1.24 1.27 1.30 1.33 1.37 1.40 1.43 1.47 1.50 1.54 1.58 1.62 1.65 1.69 1.74 1.78 1.82 1.87 1.91 1.96 2.00 2.05 2.10 2.15 2.21 2.26 2.32 2.37 2.43 2.49 2.55 2.61 2.77 2.74 2.80 2.87 2.94 3.01 3.09 3.16 3.24 3.32 3.40 3.48 3.57 3.65 3.74 3.83 3.92 4.02 4.12 4.22 4.32 4.42 4.53 4.64 4.75 4.87 4.99 5.11 5.23 5.36 5.49 5.62 5.76 5.90 6.04 6.19 6.34 6.49 6.65 6.81 6.98 7.15 7.32 7.50 7.68 7.87 8.06 8.25 8.45 8.66 8.87 9.09 9.31 9.53 9.76 ];
RE96= [];


for k=0:6
	RE96 = [RE96 RE96_.*10^k ] ;
endfor

RE96=RE96(RE96<= E96MAX);
RE96=RE96';                   




%------------  USER INTERACTION --------------------------%
%
%


disp('Resistor calculator 0.0')

R= input('Enter with the resistor Value in ohms: ');
disp('Best resistor value and error in %:');
disp(' ')


	% ---- E12 resistor value ------ %
fprintf('---------------------------------\n')
disp('E12 resistor serie 10% tolerance:')
ERR  = abs((R-RE12)/R)*100;  % Erro in %
err = min(ERR)		     % Get the minimum error
RB_E12 = RE12(ERR==err)	     % Get the better value for RE12
fprintf('R='); resistor_print(RB_E12); fprintf('\n')

# Calculate the equivalent sum of resistors
RES=RE12;
fprintf('\n');
fprintf('Resistor sum:\n')
resistor_sum
disp(' ')


	% ---- E24 resistor value ------ %
fprintf('---------------------------------\n')
disp('E24 resistor serie 5% tolerance:') 
ERR  = abs((R-RE24)/R)*100;  % Erro in %
err = min(ERR)		     % Get the minimum error
RB_E24 = RE24(ERR==err)	     % Get the better value for RE24 
fprintf('R='); resistor_print(RB_E12); fprintf('\n')

# Calculate the equivalent sum of resistors
RES=RE24;
fprintf('\n');
fprintf('Resistor sum:\n')
resistor_sum          
disp(' ')

 	% ---- E96 resistor value ------ %
fprintf('---------------------------------\n')
disp('E96 resistor serie 1% tolerance:') 
ERR  = abs((R-RE96)/R)*100;  % Erro in %
err = min(ERR)		     % Get the minimum error
RB_E96 = RE96(ERR==err)	     % Get the better value for RE96 
fprintf('R='); resistor_print(RB_E12); fprintf('\n')

# Calculate the equivalent sum of resistors
RES=RE96;
fprintf('\n');
fprintf('Resistor sum:\n')
resistor_sum          
disp(' ')                           

