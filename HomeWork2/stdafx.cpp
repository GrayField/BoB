// stdafx.cpp : 표준 포함 파일만 들어 있는 소스 파일입니다.
// ConsoleApplication1.pch는 미리 컴파일된 헤더가 됩니다.
// stdafx.obj에는 미리 컴파일된 형식 정보가 포함됩니다.

#include "stdafx.h"

// TODO: 필요한 추가 헤더는
// 이 파일이 아닌 STDAFX.H에서 참조합니다.

void print(_In_ const char* fmt, _In_ ...)
{
	char log_buffer[2048];
	va_list args;

	va_start(args, fmt);
	HRESULT hRes = StringCbVPrintfA(log_buffer, sizeof(log_buffer), fmt, args);
	if (S_OK != hRes)
	{
		fprintf(
			stderr,
			"%s, StringCbVPrintfA() failed. res = 0x%08x",
			__FUNCTION__,
			hRes
			);
		return;
	}

	OutputDebugStringA(log_buffer);
	fprintf(stdout, "%s \n", log_buffer);
}

bool is_file_existsW(_In_ const wchar_t* file_path)
 {
	 	_ASSERTE(NULL != file_path);
	 	_ASSERTE(TRUE != IsBadStringPtrW(file_path, MAX_PATH));
	 	if ((NULL == file_path) || (TRUE == IsBadStringPtrW(file_path, MAX_PATH))) return false;
	

		 	WIN32_FILE_ATTRIBUTE_DATA info = { 0 };
	

		 	// 
		 	// CreateFile()이 아닌 GetFileAttributesEx()를 이용하면 파일이 다른 process에 의해 lock되어 있어도 
		 	// 파일 존재여부를 정확히 체크할 수 있다. 
		 	// 
		 	if (GetFileAttributesExW(file_path, GetFileExInfoStandard, &info) == 0)
		 		return false;
	 	else
			return true;
	 }

