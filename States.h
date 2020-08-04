//
// Created by Richard Robinson on 2020-08-04.
//

#ifndef UNTITLED6_STATES_H
#define UNTITLED6_STATES_H


#include "ModernStateContext.h"

namespace Modern {

    struct WaitNState: StateContext::State {
        int out() override {
            return 0x22;
        }

        void onUpdate(int input, StateContext *context) override;
    };

    struct WaitEState: StateContext::State {
        int out() override {
            return 0x14;
        }

        void onUpdate(int input, StateContext *context) override;
    };

    struct GoEState: StateContext::State {
        int out() override {
            return 0x0C;
        }

        void onUpdate(int input, StateContext *context) override;
    };

    struct GoNState: StateContext::State {
        int out() override {
            return 0x21;
        }

        void onUpdate(int input, StateContext *context) override;
    };

}


#endif //UNTITLED6_STATES_H
