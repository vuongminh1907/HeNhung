#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    virtual void updateScore(int score) = 0;
    virtual void updateHighScore(int highScore) = 0;
    virtual void updateWeight(int weight) = 0;
    virtual void updateScale() = 0;

    void bind(Model* m)
    {
        model = m;
    }
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
