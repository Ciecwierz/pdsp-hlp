typedef enum {
    IIR_DirectFormI = 0,
    IIR_DirectFormII = 1,
    IIR_DirectFormITransposed = 2,
    IIR_CascadeForm = 3
} IIR_FormType_t;

typedef struct {

    float * pCoeffA;
    float * pCoeffB;
    uint32_t order;
    IIR_FormType_t form;

} IIR_Config_t;

typedef struct {
    IIR_Config_t * pCfg;
    float * pDelayX;
    float * pDelayY;
} IIR_Handle_t;


void IIR_Init  (IIR_Handle_t * pHandle, IIR_Config_t * pConfig) {

    pHandle->pCfg = pConfig;
    if(pConfig->form == IIR_DirectFormI){

        pHandle->pDelayX = (float * )malloc((pConfig->order + 1)* sizeof(float));

        memset(pHandle->pDelayX,0,(pConfig->order + 1) * sizeof(float));

    }

    pHandle->pDelayY = (float*)malloc((pConfig->order + 1) * sizeof(float));

    memset(pHandle->pDelayY,0,(pConfig->order + 1) * sizeof(float));
    
}

float IIR_GetValue(IIR_Handle_t* pHandle, float sample){
    uint32_t n;
    uint32_t order  = pHandle->pCfg->order;
    float * pCoeffA = pHandle->pCfg->pCoeffA;
    float * pDelayX = pHandle->pDelayX;
    flooat * pCoeffB = pHandle->pCfg->pCoeffB;
    float * pDelayY = pHandle->pDelayY;
    float output = 0.0f;


    pDelayX[0] = sample;


    for(n = 0; n <= order; n++){
        output += pDelayX[n] * pCoeffB[n];
    }
    for(n = 1; n <= order; n++){
        output -= pDelayY[n] * pCoeffA;
    }

    pDelayY[0] = output;

    for(n = order; n> 0; n--) {
        pDelayX[n] = pDelayX[n - 1];
        pDelayY[n] = pDelayY[n - 1];

    }

    return output;
}





//3.1.6


typedef struct {
    FIR_Config_t * pCfg;
    float * pDelay; 
    float * pDelayIndex;

} FIR_RingPointer_Handle_t;

typedef struct {
    FIR_Config_t * pCfg;
    float * pDelay;
    uint32_t Index;
} FIR_RingIndex_Handle_t;


void FIR_RingPointer_Init (FIR_RingPointer_Handle_t * pHandle, FIR_Config_t * pConfig) {

    pHandle->pCfg = pConfig;

    pHandle->pDelay = (float*)malloc((pConfig->order  + 1) * sizeof(float));

    memset(pHandle->pDelay, 0 , (pConfig->order + 1) * sizeof(float));

    pHandle->pDelayIndex = pHandle->pDelay;
}



float FOR_RingPointer_GetValue(FIR_RingPointer_Handle_t * pHandle, float sample) {
    uint32_t n;
    uint32_t order = pHandle->pCfg->order;
    float * pCoeff = pHandle->pCfg->pCoeff;
    float * pDelayLine = pHandle->pDelay; //w instrukcji jest chyba pomylka, wiec poprawilem
    float * pDelayIndex = pHandle->pDelayIndex;
    float output = 0.0f;

    *pDelayIndex = sample;
    pDelayIndex++;
    if(pDelayIndex > &pHandle->pDelay[order]){
        pDelayIndex = pHandle->pDelay;
    }

    pHandle->pDelayIndex = pDelayIndex;

    for(n = 0; n <= order; n++) {
        output += (*pDelayLine) * (*pCoeff);
        pDelayLine++;
        pCoeff++;
        if(pDelayLine > &pHandle->pDelay[order]) {
            pDelayLine = pHandle->pDelay;
        }
    }
    return output;
}
void FIR_RingIndex_Init (FIR_RingIndex_Handle_t * pHandle, FIR_Config_t * pConfig) {

    pHandle->pCfg = pConfig;
    pHandle->pDelay = (float*)malloc((pConfig->order + 1)* sizeof(float));
    memset(pHandle->pDelay, 0, (pConfig->order + 1)* sizeof(float));
    pHandle->Index = 0;
}



