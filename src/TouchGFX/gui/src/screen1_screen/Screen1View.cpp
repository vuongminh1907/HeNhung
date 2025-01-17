#include <gui/screen1_screen/Screen1View.hpp>
#include <stdio.h>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::displayHighScore(int highScore) {
    Unicode::snprintf(textHighScore0Buffer, TEXTHIGHSCORE0_SIZE, "%d", highScore);
    textHighScore0.invalidate();  // Cập nhật giao diện TextArea
}

void Screen1View::buttonClicked(){
	presenter->resetHighScore();
}

void Screen1View::changeMode() {
	presenter->updateScale();
}

