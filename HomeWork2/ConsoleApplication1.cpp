// ConsoleApplication1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdint.h>
#include "StopWatch.h"
#include "mmio.h"
#include <stdio.h>
#include "FileIoHelperClass.h"


int _tmain(int argc, _TCHAR* argv[])
{
	/*
	_ASSERTE(create_very_big_file(L"big.txt", 5000));

	StopWatch sw2;
	sw2.Start();
	_ASSERTE(file_copy_using_memory_map(L"big.txt", L"big3.txt"));
	sw2.Stop();
	print("info] time elapsed = %f", sw2.GetDurationSecond());


	StopWatch sw;
	sw.Start();
	_ASSERTE(file_copy_using_read_write(L"big.txt", L"big4.txt"));
	sw.Stop();
	print("info] time elapsed = %f", sw.GetDurationSecond());
	*/

	FileIoHelper Helper;
	uint64_t size=5000;
	LARGE_INTEGER file_size;
	LARGE_INTEGER offset;
	offset.QuadPart = 0;
	DWORD bufsize = 2048*1024*1024;
	PUCHAR buf = (PUCHAR)malloc(bufsize);

	file_size.QuadPart = (1024 * 1024) * size;

	

	
	_ASSERTE(create_very_big_file(L"big.txt", size));

	StopWatch sw2;
	sw2.Start();
	Helper.FIOpenForRead(L"big.txt");
	Helper.FIOCreateFile(L"big2.txt", file_size);

	while (offset.QuadPart < file_size.QuadPart) {
		if ((file_size.QuadPart - offset.QuadPart) >(LONGLONG)bufsize)
		{
			bufsize = 2048*1024*1024;
		}
		else {
			bufsize = (DWORD)(file_size.QuadPart - offset.QuadPart);
		}

		Helper.FIOReadFromFile(offset, bufsize, buf);
		Helper.FIOWriteToFile(offset, bufsize, buf);

		offset.QuadPart += (LONGLONG)bufsize;
	}

	sw2.Stop();
	print("info] time elapsed = %f", sw2.GetDurationSecond());


	StopWatch sw;
	sw.Start();
	_ASSERTE(file_copy_using_read_write(L"big.txt", L"big3.txt"));
	sw.Stop();
	print("info] time elapsed = %f", sw.GetDurationSecond());



	
	_getwch();
	return 0;
}

