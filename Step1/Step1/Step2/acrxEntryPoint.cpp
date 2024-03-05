#include "arxHeaders.h"

#define szRDS _RXST("Asdk")

class CStep2App : public AcRxArxApp
{
public:
	CStep2App() : AcRxArxApp() {}

	virtual AcRx::AppRetCode On_kInitAppMsg(void* pkt) {

		AcRx::AppRetCode retCode = AcRxArxApp::On_kInitAppMsg(pkt);

		// TODO: Add your initialization code here

		return (retCode);

	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pkt) {

		AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadAppMsg(pkt);

		// TODO: Add your code here

		return (retCode);

	}

	virtual void RegisterServerComponents() {

	}

	static void AsdkStep2_myInput(void)
	{
		int in;
		int intVal;
		float realVal;
		AcString inputWord;

		acedInitGet(RSG_NOZERO | RSG_NONEG, (const ACHAR*)"Condition was violated");

		if (acedGetInt((const ACHAR*)"Please enter a intVal", &intVal) != RTNORM) return;

		in = acedGetString(0, (const ACHAR*)"Please choose A, B, C, or PI", inputWord);

		switch (in)
		{
		case RTERROR:
			return;
		case RTCAN:
			return;
		case RTNONE:
			realVal = 12.0f;
			break;
		case RTNORM:
			if (AcString::equalsNoCase(inputWord, (wchar_t)"PI")) realVal = 3.14f;
			else if (AcString::equalsNoCase(inputWord, (wchar_t)"A")) realVal = 10.0f;
			else if (AcString::equalsNoCase(inputWord, (wchar_t)"B")) realVal = 11.0f;
			else if (AcString::equalsNoCase(inputWord, (wchar_t)"C")) realVal = 12.0f;
			else
			{
				acutPrintf((const ACHAR*)"Wrong input");
				return;
			}
		}

		acutPrintf((const ACHAR*)"Ur integer is %d", intVal);
		acutPrintf((const ACHAR*)"Ur real value is %lf", realVal);
	}

	static void AsdkStep02_mySelect(void) {
		ads_name n;
		ads_point p;

		if (acedEntSel((const ACHAR*)"entity", n, p) != RTNORM) return;

		acutPrintf((const ACHAR*)"You selected entity %ld", n[0]);
	}
};

