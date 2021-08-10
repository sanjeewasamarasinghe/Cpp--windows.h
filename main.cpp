#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>

HWND button,lable,textBox;

void functionTextAdd(){
	
		
		MessageBox(0, "xx>", "xx", MB_OK | MB_ICONQUESTION);
		
		
	};
	

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	

	
	
	switch(Message) {
		
		
		
	
		
		case WM_CREATE:
			
			button = CreateWindow( 
			    "BUTTON",  // Predefined class; Unicode assumed 
			    "OK",      // Button text 
			    WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
			    500,         // x position 
			    300,         // y position 
			    100,        // Button width
			    100,        // Button height
			    hwnd, 
				(HMENU)1,    // Parent window
			    NULL,       // No menu.
			    NULL);
			    
			    lable = CreateWindow("static", "This Is MY C++ Findings",
                              WS_CHILD | WS_VISIBLE | WS_TABSTOP,
                              200, 300, 200, 100,
                              hwnd, (HMENU)(501),
                              (HINSTANCE) GetWindowLong (hwnd, GWL_HINSTANCE), NULL);
                              
                textBox = CreateWindowEx(WS_EX_CLIENTEDGE, "edit", "Enter Your Name",
                              WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER | ES_LEFT,
                              10, 10, 200, 150,
                              hwnd, (HMENU)(123),
                              (HINSTANCE) GetWindowLong (hwnd, GWL_HINSTANCE), NULL);
			    
			break;
			
		case WM_COMMAND:{
		
				switch  (LOWORD(wParam)) 
				{  
				case 1:
				//::MessageBeep(NULL,NULL);
				//::MessageBox(hwnd,"XX","XX",MB_ICONEXCLAMATION);
				//::MessageBox(hwnd,"XX","XX",MB_ICONASTERISK);
				//::MessageBox(hwnd,"XX","XX",MB_ICONHAND);
				//::MessageBox(hwnd,"XX","XX",MB_ICONQUESTION);
				//::MessageBox(hwnd,"XX","XX",MB_OK);
				functionTextAdd();
				break ;
				}
			    //if ((HIWORD(wParam) == BN_CLICKED) && (lParam != 0))
			    //{
			        //HWND hwndBtn = (HWND) lParam;
			
			        //if (hwndBtn == button)
			            //::MessageBox(hwnd,"XX","XX",MB_OK);
			            
			    //}
			
			    break;	
			    
			}
			
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: 
			PostQuitMessage(0);
			break;
		
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */
	


	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
