CODEC_DataFloat_t gFirIn;
CODEC_DataFloat_t gFirOut;
FIR_Config_t gFirLP_Cfg;
FIR_Handle_t gFirLP_Handle;

void main(){
    PDSP_Init();
    PDSP_CODEC_Init();
    PDSP_INT_Init();

    //Initialize FIR coefficients
    FIR_SetConfigCoeff(&gFirLP_Cfg, (float *)B, BL);
    //Initialize FIR filter
    FIR_Init(&gFirLP_Handle, &gFirLP_Cfg);

    while(1){
        //Przetwarzanie przez odpytywania

    }

}


void FIR_CoeffLP(FIR_Config_t * pConfig, float fc, uint32_t order){
    uint32_t n;
    float sinValue, decimator, coeff;
    //
    pConfig->order = order;
    float wc = 2.0f * PDSP_PI * fc / CODEC_fs;
    float alpha = pConfig->order * 0.5f;
    //
    pConfig->pCoeff = (float *)malloc((pConfig->order + 1) * sizeof(float)); 
    //
    for(n=0; n<= pConfig->order; n++){
        sinValue = sinf(wc * ((float)n - alpha));
        decimator = PDSP_PI *((float)n - alpha);
        if(pConfig->order % 2 == 1){
            coeff = sinValue / decimator;
        } else {
            if(n == (uint32_t)(pConfig->order / 2)) {
                coeff = wc / PDSP_PI;
            } else {
                coeff = sinValue / decimator;
            }
        }
        pConfig->pCoeff[n] = coeff;
    }
}