// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <stdint.h>
#include <Windows.h>
#include <crtdbg.h>
#include <strsafe.h>

void print(_In_ const char* fmt, _In_ ...);
bool is_file_existsW(_In_ const wchar_t* file_path);
wchar_t* get_current_directory(void);


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
