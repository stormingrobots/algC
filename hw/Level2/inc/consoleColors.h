#ifndef _CONSOLE_COLOR_HEADER 
#define _CONSOLE_COLOR_HEADER 



#include <stdio.h>
// 8 colors only
//  \u001b      - set console color
//        [#    - text color
//           m  - end


// 16 colors only
//  \u001b         - set console color
//        [#;      - text color
//           #;    - 1-bold, 4-underline, 
//              m  - end

// 256 colors
//  \u001b[38;5;    - set console color
//              #   - text color
//               m  - end

// ------------- set background --------------------
//  \u001b[48;5;
//              #       - background color
//               ;1     - 1-bright
//                 m    - end
// e.g.
//   \u001b[38;5;196m Foreground color : red
//   \u001b[48;5; 0m   Background color: black
// or  in linux command prompt 
//   \e[38; 5; 196m Foreground color : red
//   \e[48; 5; 0m   Background color: black


extern  const char* Color_Off;

// 8 colors list  ==========================================
extern  const char* Black;
extern  const char* Red;
extern  const char* Green;
extern  const char* Yellow;
#endif