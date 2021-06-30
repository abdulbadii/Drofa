#include "eval.h"

#ifdef _TUNE_
    #define TRACK (1)
#else
    #define TRACK (0)
#endif

// This structure holds all features we want to tune
// that is traced as we Evalute position
struct posFeatured{

    //whole finalEval
    int FinalEval;
    //scaling consts
    bool OCBscale;

    // Simple features
    // a. Piece Values
    int PawnValue[2];
    int RookValue[2];
    int KnightValue[2];
    int BishopValue[2];
    int QueenValue[2];
    // b. other simple
    int BishopPair[2];
    int KingHighDanger[2];
    int KingMedDanger[2];
    int KingLowDanger[2];
    int PawnSupported[2];
    int PawnDoubled[2];
    int PawnIsolated[2];
    int PawnBlocked[2];
    int PassersBlocked[2];
    int BishopRammed[2];
    int BishopCenterControl[2];
    int MinorBehindPawn[2];
    int MinorBehindPasser[2];
    int KingAheadPasser[2];
    int KingEqualPasser[2];
    int KingBehindPasser[2];
    int KingOpenFile[2];
    int KingSemiOwnFile[2];
    int KingSemiEnemyFile[2];
    int KingAttackPawn[2];
    //Array features
    int PawnConnected[7][2];
    int PassedPawnRank[8][2];
    int PassedPawnFile[8][2];
    int PassedPawnFree[7][2];
    int PassedPawnPosAdvance[7][2];
    int PassedPassedDistance[8][2];
    int KingFriendlyPasser[9][2];
    int KingEnemyPasser[9][2];
    int RookOpenFile[2][2];
    int RookHalfFile[2][2];
    int HangingPiece[5][2];
    int MinorAttackedBy[5][2];
    int RookAttackedBy[5][2];
    //Array - Safety Shields
    int KingShieldKS[8][2];
    int KingShieldQS[8][2];
    //Array Features  - Mobility
    int BishopMobility[14][2];
    int KnigthMobility[9][2];
    int KingMobility[9][2];
    int RookMobility[15][2];
    int QueenMobility[28][2];
    //Array features - PSQT
    int KingPsqtBlack[64][2];
    int PawnPsqtBlack[64][2];
    int RookPsqtBlack[64][2];
    int BishopPsqtBlack[64][2];
    int KnightPsqtBlack[64][2];
    int QueenPsqtBlack[64][2];
    //Array features - PSQT-like
    int KnightOutProtBlack[64][2];
    int BishopOutProtBlack[64][2];
    int KnightOutBlack[64][2];
    int BishopOutBlack[64][2];
};

struct eTrace {
    int16_t index;
    int16_t count;

    eTrace(int16_t i, int16_t c) : index(i), count(c) {}
};

struct tEntry {
    int16_t statEval;
    int16_t phase;
    int16_t tracesCount;
    int FinalEval;
    double result;
    double pFactors[2];
    bool stm;
    bool OCBEndgame;
    bool noPawns;
    eTrace *traces;
};


 /**
  * @brief Main tuning constants are defined here
  * @{
  */
  const std::string TUNING_DATA        = "BOOK.txt";
  const int         TUNING_POS_COUNT   = 42484641; //9996883 42484641
  const int         TUNING_THREADS     = 16;
  const int         TUNING_TERMS_COUNT = 838;
  const int         TUNING_BATCH_SIZE  = 0;
  const int         TUNIGN_MAX_ITER    = 2500;
  const int         TUNIGN_PRINT       = 25; 
  const int         TUNING_K_PRECISION = 10;
  const int         TUNING_L_STEP      = 1500;
  const double      TUNING_K           = 2.746758999;
  const double      TUNING_L_DROP      = 1.0;
  const double      TUNING_L_RATE      = 10.0;

  const int         TUNING_STACK_SIZE = ((int)((double) TUNING_POS_COUNT * TUNING_TERMS_COUNT / 64));
  /**@}*/

  // 
  
  typedef double tValueHolder[TUNING_TERMS_COUNT][2];
  typedef double featureCoeff[TUNING_TERMS_COUNT];


  #define strFail (std::string::npos)
 /** 
  * @brief run the tuner using data specified in the TUNING_DATA
  *        All other stuff is private because it is not needed anywhere else.
  */
 void TunerStart();

 /**
  * @brief print simple term (op, eg)
  * 
  * @param name  name of the term
  * @param value OPENING value of the term
  * @param value ENDGAME value of the term
  * 
  */ 
 void EvalTermPrint(std::string, double, double, double, double);
 
 void EvalArrayPrint(std::string, tValueHolder, tValueHolder, int, int, int);
 
 void EvalTermInitiate(tValueHolder);

 bool InitTuningPositions(tEntry*);

 void InitSinglePosition(int, std::string, tEntry*);

 void InitCoefficients(featureCoeff);

 void InitETraces(featureCoeff, tEntry*);

 void CalculateGradient(tEntry*, tValueHolder, tValueHolder);

 void UpdateSingleGrad(tEntry*, tValueHolder, tValueHolder);

 double Sigmoid(double);

 double SigmoidForK(double);

 double TuningEval(tEntry*, tValueHolder);

 double TunedError(tEntry*, tValueHolder);

 double StaticError(tEntry *, double);

 void PrintTunedParams(tValueHolder, tValueHolder);

 double CalculateFactorK(tEntry *);

 int simplifyPhaseCalculation(const Board &board);

 void CheckFeaturesNumber();