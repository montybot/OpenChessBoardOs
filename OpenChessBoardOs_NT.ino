// https://playground.arduino.cc/Main/KeypadTutorial/
// https://playground.arduino.cc/Code/Keypad/
#include <Keypad.h>

// include the SevenSegmentTM1637 library
// https://github.com/bremme/arduino-tm1637
#include "SevenSegmentTM1637.h"

// Keypad data
const byte ROWS = 8; //8 rows
const byte COLS = 8; //8 columns

// See teeensy duino mapping
// https://www.pjrc.com/store/teensypp.html

// Original creation SolusChess
// https://sites.google.com/view/berger-projects/en/other-repairs-projects/soluschess?authuser=0 

// 8 to 1
byte rowPins[ROWS] = {A0, A1, A2, A3, A4, A5, A6, A7}; //connect to the row pinouts of the keypad

// A to H
byte colPins[COLS] = {17, 16, 15, 14, 13, 12, 11, 10}; //connect to the column pinouts of the keypad

// Board Teensy ++ Led for debuging
int ledPin = 6;

char chessBoardKeys[ROWS][COLS] = {
  {'1', '2', '3', '4', '5', '6', '7', '8'}, // |A8 | B8 | C8 | D8 | E8 | F8 | G8 | H8 |
  {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'}, // |A7 | B7 | C7 | D7 | E7 | F7 | G7 | H7 |
  {'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'}, // |A6 | B6 | C6 | D6 | E6 | F6 | G6 | H6 |
  {'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'}, // |A5 | B5 | C5 | D5 | E5 | F5 | G5 | H5 |
  {'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f'}, // |A4 | B4 | C4 | D4 | E4 | F4 | G4 | H4 |
  {'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'}, // |A3 | B3 | C3 | D3 | E3 | F3 | G3 | H3 |
  {'o', 'p', 'q', 'r', 's', 't', 'u', 'v'}, // |A2 | B2 | C2 | D2 | E2 | F2 | G2 | H2 |
  {'w', 'x', 'y', 'z', '!', '@', '#', '$'}  // |A1 | B1 | C1 | D1 | E1 | F1 | G1 | H1 |
};

// Keypad matrix for Black or White player
Keypad keypadBoard = Keypad( makeKeymap(chessBoardKeys), rowPins, colPins, ROWS, COLS );

// Keypressed on the chessboard
char keypressed;

/////////////////////////////////
// 4 digits display
/////////////////////////////////
// Brightness level in percent
const byte DISPLAY_BRIGHTNESS = 10;
// Digital display pins for tm1637 4 digits 7 segments module
const byte PIN_CLK = 2;   // define CLK pin (any digital pin)
const byte PIN_DIO = 3;   // define DIO pin (any digital pin)
SevenSegmentTM1637    display(PIN_CLK, PIN_DIO);

// Move place on the display
int moveNumber = 0;

// Display moves entered on the chessboard on the 4 digits 7 segments (TM1637 display)
void displayMove(const String& thisIsAString) {
  if (moveNumber == 0) {
    display.clear();
    display.setCursor(1, 0);
    display.print(thisIsAString); // Display move on the first and second digit       
    moveNumber = 1; //place the cursor on 3 & 4 ditgits to diplay the next move
  } else {
    display.setCursor(1, 2);
    display.print(thisIsAString); // Display move on the third an fourth digit       
    moveNumber = 0; //place the cursor on 1 & 2 ditgits to diplay the next move
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);
  //pinMode(flipBoardPin, INPUT);
  ////Serial.begin(9600);
  //flipBoardPinStat = digitalRead(flipBoardPin);
  Serial.begin(9600);         // initializes the Serial connection @ 9600 baud
  display.begin();            // initializes the display
  display.setBacklight(DISPLAY_BRIGHTNESS);  // set the brightness to 100 %
  display.print("PLAY");      // display INIT on the display
  delay(1000);                // wait 1000 ms
  display.setColonOn(true);
  display.clear();
}

void loop() {
  //flipBoardPinStat = digitalRead(flipBoardPin);
  delay(10);
  keypressed = '\n';
  // Handle the keypressed on the board with flip board test

    keypressed = keypadBoard.getKey();
    delay(10);

// Chessboard act as a usb keyboard and return the coordinate of the case pressed on the board
// Tested and working on linux, w10 and android

  if (keypressed != NO_KEY) {
  // Send the board code by serial connection
    ////Serial.println(flipBoardPinStat);
    ////Serial.println(key); // Row 8

    switch (keypressed) {
      case '1':
        Keyboard.write("a8");
        ////Serial.println("a8"); // Row 8
        displayMove("a8");
        break;
      case '2':
        Keyboard.write("b8");
        //Serial.println("b8");
        displayMove("b8");
        break;
      case '3':
        Keyboard.write("c8");
        //Serial.println("c8");
        displayMove("c8");
        break;
      case '4':
        Keyboard.write("d8");
        //Serial.println("d8");
        displayMove("d8");
        break;
      case '5':
        Keyboard.write("e8");
        //Serial.println("e8");
        displayMove("e8");
        break;
      case '6':
        Keyboard.write("f8");
        //Serial.println("f8");
        displayMove("f8");
        break;
      case '7':
        Keyboard.write("g8");
        //Serial.println("g8");
        displayMove("g8");
        break;
      case '8':
        Keyboard.write("h8");
        //Serial.println("h8");
        displayMove("h8");
        break;

      case 'A':
        Keyboard.write("a7"); // Row 7
        //Serial.println("a7"); // Row 7
        displayMove("a7");
        break;
      case 'B':
        Keyboard.write("b7");
        //Serial.println("b7");
        displayMove("b7");
        break;
      case 'C':
        Keyboard.write("c7");
        //Serial.println("c7");
        displayMove("c7");
        break;
      case 'D':
        Keyboard.write("d7");
        //Serial.println("d7");
        displayMove("d7");
        break;
      case 'E':
        Keyboard.write("e7");
        //Serial.println("e7");
        displayMove("e7");
        break;
      case 'F':
        Keyboard.write("f7");
        //Serial.println("f7");
        displayMove("f7");
        break;
      case 'G':
        Keyboard.write("g7");
        //Serial.println("g7");
        displayMove("g7");
        break;
      case 'H':
        Keyboard.write("h7");
        //Serial.println("h7");
        displayMove("h7");
        break;

      case 'I':
        Keyboard.write("a6"); // Row 6
        //Serial.println("a6"); // Row 6
        displayMove("a6");
        break;
      case 'J':
        Keyboard.write("b6");
        //Serial.println("b6");
        displayMove("b6");
        break;
      case 'K':
        Keyboard.write("c6");
        //Serial.println("c6");
        displayMove("c6");
        break;
      case 'L':
        Keyboard.write("d6");
        //Serial.println("d6");
        displayMove("d6");
        break;
      case 'M':
        Keyboard.write("e6");
        //Serial.println("e6");
        displayMove("e6");
        break;
      case 'N':
        Keyboard.write("f6");
        //Serial.println("f6");
        displayMove("f6");
        break;
      case 'O':
        Keyboard.write("g6");
        //Serial.println("g6");
        displayMove("g6");
        break;
      case 'P':
        Keyboard.write("h6");
        //Serial.println("h6");
        displayMove("h6");
        break;
      case 'Q':
        Keyboard.write("a5"); // Row 5
        //Serial.println("a5"); // Row 5
        displayMove("a5");
        break;
      case 'R':
        Keyboard.write("b5");
        //Serial.println("b5");
        displayMove("b5");
        break;
      case 'S':
        Keyboard.write("c5");
        //Serial.println("c5");
        displayMove("c5");
        break;
      case 'T':
        Keyboard.write("d5");
        //Serial.println("d5");
        displayMove("d5");
        break;
      case 'U':
        Keyboard.write("e5");
        //Serial.println("e5");
        displayMove("e5");
        break;
      case 'V':
        Keyboard.write("f5");
        //Serial.println("f5");
        displayMove("f5");
        break;
      case 'W':
        Keyboard.write("g5");
        //Serial.println("g5");
        displayMove("g5");
        break;
      case 'X':
        Keyboard.write("h5");
        //Serial.println("h5");
        displayMove("h5");
        break;

      case 'Y':
        Keyboard.write("a4"); // Row 4
        //Serial.println("a4"); // Row 4
        displayMove("a4");
        break;
      case 'Z':
        Keyboard.write("b4");
        //Serial.println("b4");
        displayMove("b4");
        break;
      case 'a':
        Keyboard.write("c4");
        //Serial.println("c4");
        displayMove("c4");
        break;
      case 'b':
        Keyboard.write("d4");
        //Serial.println("d4");
        displayMove("d4");
        break;
      case 'c':
        Keyboard.write("e4");
        //Serial.println("e4");
        displayMove("e4");
        break;
      case 'd':
        Keyboard.write("f4");
        //Serial.println("f4");
        displayMove("f4");
        break;
      case 'e':
        Keyboard.write("g4");
        //Serial.println("g4");
        displayMove("g4");
        break;
      case 'f':
        Keyboard.write("h4");
        //Serial.println("h4");
        displayMove("h4");
        break;

      case 'g':
        Keyboard.write("a3"); // Row 3
        //Serial.println("a3"); // Row 3
        displayMove("a3");
        break;
      case 'h':
        Keyboard.write("b3");
        //Serial.println("b3");
        displayMove("b3");
        break;
      case 'i':
        Keyboard.write("c3");
        //Serial.println("c3");
        displayMove("c3");
        break;
      case 'j':
        Keyboard.write("d3");
        //Serial.println("d3");
        displayMove("d3");
        break;
      case 'k':
        Keyboard.write("e3");
        //Serial.println("e3");
        displayMove("e3");
        break;
      case 'l':
        Keyboard.write("f3");
        //Serial.println("f3");
        displayMove("f3");
        break;
      case 'm':
        Keyboard.write("g3");
        //Serial.println("g3");
        displayMove("g3");
        break;
      case 'n':
        Keyboard.write("h3");
        //Serial.println("h3");
        displayMove("h3");
        break;

      case 'o':
        Keyboard.write("a2"); // Row 2
        //Serial.println("a2"); // Row 2
        displayMove("a2a2");
        break;
      case 'p':
        Keyboard.write("b2");
        //Serial.println("b2");
        displayMove("b2");
        break;
      case 'q':
        Keyboard.write("c2");
        //Serial.println("c2");
        displayMove("c2");
        break;
      case 'r':
        Keyboard.write("d2");
        //Serial.println("d2");
        displayMove("d2");
        break;
      case 's':
        Keyboard.write("e2");
        //Serial.println("e2");
        displayMove("e2");
        break;
      case 't':
        Keyboard.write("f2");
        //Serial.println("f2");
        displayMove("f2");
        break;
      case 'u':
        Keyboard.write("g2");
        //Serial.println("g2");
        displayMove("g2");
        break;
      case 'v':
        Keyboard.write("h2");
        //Serial.println("h2");
        displayMove("h2");
        break;

      case 'w':
        Keyboard.write("a1"); // Row 1
        //Serial.println("a1"); // Row 1
        displayMove("a1");
        break;
      case 'x':
        Keyboard.write("b1");
        //Serial.println("b1");
        displayMove("b1");
        break;
      case 'y':
        Keyboard.write("c1");
        //Serial.println("c1");
        displayMove("c1");
        break;
      case 'z':
        Keyboard.write("d1");
        //Serial.println("d1");
        displayMove("d1");
        break;
      case '!':
        Keyboard.write("e1");
        //Serial.println("e1");
        displayMove("e1");
        break;
      case '@':
        Keyboard.write("f1");
        //Serial.println("f1");
        displayMove("f1");
        break;
      case '#':
        Keyboard.write("g1");
        //Serial.println("g1");
        displayMove("g1");        
        break;
      case '$':
        Keyboard.write("h1");
        //Serial.println("h1");
        displayMove("h1");
        break;
    }

  }
}
