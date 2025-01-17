#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:

    enum ScreenState {
        SCREEN_1,
        SCREEN_2
    };

    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    // Các phương thức getter và setter
    int getScore() const;
    int getHighScore() const;
    int getWeight() const;
    int getScale() const;

    void setScore(int newScore);
    void setHighScore(int newHighScore);
    void setWeight(int newWeight);
    void setScale(int newScale);

    ScreenState getCurrentScreen() const;
    void setCurrentScreen(ScreenState screen);

protected:
    ModelListener* modelListener;
    int score;
    int highScore;
    int weight;
    int scale;
    ScreenState currentScreen;
};

#endif // MODEL_HPP
