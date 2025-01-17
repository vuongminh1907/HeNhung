#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include "cmsis_os2.h"
#include "stm32f4xx_hal.h"
#include <cstring>

// Khai báo handle của message queue (được định nghĩa ở nơi khác)
extern "C" osMessageQueueId_t myQueue01Handle;

// Constructor
Model::Model() : modelListener(0), score(0), highScore(0), weight(0), scale(1), currentScreen(SCREEN_1) {}

int Model::getScore() const {
    return score;
}

int Model::getHighScore() const {
    return highScore;
}

int Model::getWeight() const {
	return weight;
}

int Model::getScale() const {
	return scale;
}

void Model::tick() {
    int receivedData = this->getWeight();
    int m = 8 + 2 * this->getScale();

    // Kiểm tra hàng đợi message và lấy dữ liệu nếu có
    if (osMessageQueueGetCount(myQueue01Handle) > 0) {
        osMessageQueueGet(myQueue01Handle, &receivedData, NULL, 0);
    }

    // Nếu dữ liệu nhận được là âm, đặt lại thành 0
    if (receivedData < 0) {
        receivedData = 0;
    }

	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
	if (receivedData > 0 && receivedData <= m) {
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
	}
	if (receivedData > m && receivedData <= 2 * m) {
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
	}
	if (receivedData > 2 * m && receivedData <= 3 * m) {
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_RESET);
	}
	if (receivedData > 3 * m) {
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, GPIO_PIN_SET);
	}

    // Cập nhật điểm chỉ khi đang ở Screen 2
    if (currentScreen == SCREEN_2) {
        this->setWeight(receivedData);

        if (receivedData > this->getScore()) {
        	this->setScore(receivedData);
        }

        // Kiểm tra và cập nhật điểm cao nhất
        if (receivedData > this->getHighScore()) {
            this->setHighScore(receivedData);
        }
    }
}

void Model::setScore(int newScore) {
    if (currentScreen == SCREEN_2) { // Chỉ cho phép cập nhật khi ở Screen 2
        score = newScore;
        if (modelListener) {
            modelListener->updateScore(score); // Gửi dữ liệu đến listener (Presenter)
        }
    }
}

void Model::setHighScore(int newHighScore) {
	highScore = newHighScore;
	if (modelListener) {
		modelListener->updateHighScore(highScore); // Gửi dữ liệu đến listener (Presenter)
	}
}

void Model::setWeight(int newWeight) {
	weight = newWeight;
    if (modelListener) {
        modelListener->updateWeight(weight);
    }
}

void Model::setScale(int newScale) {
	scale = newScale;
    if (modelListener) {
        modelListener->updateScale();
    }
}

void Model::setCurrentScreen(ScreenState screen) {
    currentScreen = screen;
}
