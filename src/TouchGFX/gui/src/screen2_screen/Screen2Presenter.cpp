#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <gui/model/Model.hpp>

Screen2Presenter::Screen2Presenter(Screen2View& v)
    : view(v)
{

}

void Screen2Presenter::activate()
{
	model->setCurrentScreen(Model::SCREEN_2);

	int highScore = model->getHighScore();
	int score = model->getScore();

    // Cập nhật dữ liệu cho View
    view.displayScore(score);
    view.displayHighScore(highScore);
}

void Screen2Presenter::deactivate()
{

}

void Screen2Presenter::updateScore(int score)
{
    // Gọi phương thức trong Screen2View để cập nhật giao diện
    view.displayScore(score);
}

void Screen2Presenter::updateHighScore(int highScore)
{
    // Gọi phương thức trong Screen2View để cập nhật giao diện
    view.displayHighScore(highScore);
}

void Screen2Presenter::updateWeight(int weight)
{

}

void Screen2Presenter::updateScale()
{

}

void Screen2Presenter::resetScore() {
	model->setScore(0);
}



