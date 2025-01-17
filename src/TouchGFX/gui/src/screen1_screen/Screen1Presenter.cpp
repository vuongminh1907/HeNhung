#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{
	model->setCurrentScreen(Model::SCREEN_1);
    // Lấy điểm cao nhất từ Model
    int highScore = model->getHighScore();

    // Gửi điểm cao nhất đến View
    view.displayHighScore(highScore);
}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::updateScore(int Score)
{

}

void Screen1Presenter::updateHighScore(int highScore)
{
    // Gửi điểm cao nhất mới tới View
    view.displayHighScore(highScore);
}

void Screen1Presenter::resetHighScore() {
	model->setHighScore(0);
}

void Screen1Presenter::updateWeight(int weight)
{

}

void Screen1Presenter::updateScale()
{
	model->setScale(model->getScale() * (-1));
}
