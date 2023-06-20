




for(int n = 0; n < order; n++){
   v[n] = x[n];

    if(n>= 1) {

        for(int i = 1; i <=n;i++) {
            v[n]-= pCoeffA[i] * v[n-1];
        }
    }


}

   



for(int n = 0;n <order; n++ ) {
 
    y[n] = pCoeffB[0] * v[n];

    if(n >= 1) {
        for(int i = 1; i <= n; i++) {

        y[n] += pCoeffB[i] * v[n-1];
    }
    }
        
   

    
}



