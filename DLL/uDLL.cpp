#include <Vcl.h>
using namespace std;

BYTE GetBit(BYTE B, int N) {
	if ((1 << N) & B) return 1;
	return 0;
}

BYTE ChangeByte(BYTE B, int bit) {
	if (GetBit(B, 0) == bit) return B;
	else if (GetBit(B, 0) == 1 && bit == 0) return B-1;
	else if (GetBit(B, 0) == 0 && bit == 1) return B|bit;
	return NULL;
}

extern "C" TColor __declspec(dllexport) __stdcall Crypt(TColor Color, char c, int j) {
	int R,G,B;
	int bit = GetBit(c, 7-j);
	R = GetRValue(Color);
	G = GetGValue(Color);
	B = GetBValue(Color);
	R = ChangeByte(R, bit);
	TColor res = TColor RGB(R, G, B);
	return res;
}

extern "C" int __declspec(dllexport) __stdcall Decrypt(TColor Color, int ibuf, int j) {
	int R,G,B;
	R = GetRValue(Color);
	ibuf = ibuf + GetBit(R, 0) * pow(2, 7-j);
	return ibuf;
}
