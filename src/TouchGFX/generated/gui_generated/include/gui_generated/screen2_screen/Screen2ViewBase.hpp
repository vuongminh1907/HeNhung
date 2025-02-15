/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN2VIEWBASE_HPP
#define SCREEN2VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>

class Screen2ViewBase : public touchgfx::View<Screen2Presenter>
{
public:
    Screen2ViewBase();
    virtual ~Screen2ViewBase();
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void buttonClicked()
    {
        // Override and implement this function in Screen2
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::ScalableImage scalableImage1;
    touchgfx::TextArea textHighScore;
    touchgfx::TextAreaWithOneWildcard textHighScore1;
    touchgfx::TextAreaWithOneWildcard textScore;
    touchgfx::Button buttonHome;
    touchgfx::ButtonWithLabel buttonRestart;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTHIGHSCORE1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textHighScore1Buffer[TEXTHIGHSCORE1_SIZE];
    static const uint16_t TEXTSCORE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar textScoreBuffer[TEXTSCORE_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen2ViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // SCREEN2VIEWBASE_HPP
