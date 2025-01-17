#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <gui/model/Model.hpp>

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::displayScore(int score)
{
    Unicode::snprintf(textScoreBuffer, TEXTSCORE_SIZE, "%d", score);
    textScore.invalidate();  // Cập nhật giao diện TextArea
}

void Screen2View::displayHighScore(int highScore)
{
    Unicode::snprintf(textHighScore1Buffer, TEXTHIGHSCORE1_SIZE, "%d", highScore);
    textHighScore1.invalidate();  // Cập nhật giao diện TextArea
}

void Screen2View::buttonClicked(){
	presenter->resetScore();
}


