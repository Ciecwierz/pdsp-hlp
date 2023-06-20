


float GetValue_Direct_Form_II( ) {
float  output = 0.0f;

pDelayX[0] = sample;
v[0] = sample;
for(int n = 1; n < order; n++){
    v[n] -= pCoeffA[n]*pDelayX[n -1];
}

    y[0] = pCoeffB[0] * v[0];



for(int n = 1;n <order; n++ ) {

    
    
        y[n] += (pCoeffB[n] *  v[n-1]);
        output += y[n];
   

    
}



return output;
}