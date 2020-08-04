//
// Created by Richard Robinson on 2020-08-04.
//

#ifndef UNTITLED6_SEMIOOPSTATECONTEXT_H
#define UNTITLED6_SEMIOOPSTATECONTEXT_H


namespace Semi {
    enum class State {
        GO_N, WAIT_N, GO_E, WAIT_E
    };

    class StateContext {
    public:
        int light = 0;

        explicit StateContext(State initialState) : currentState(initialState) {
            light = lightFor(initialState);
        }

        void update(int input) {
            switch (currentState) {
                case State::WAIT_N:
                    updateWaitNState(input);
                    break;

                case State::WAIT_E:
                    updateWaitEState(input);
                    break;

                case State::GO_E:
                    updateGoEState(input);
                    break;

                case State::GO_N:
                    updateGoNState(input);
                    break;

                default:
                    exit(1);
            }

            light = lightFor(currentState);
        }

    private:
        State currentState;

        static int lightFor(State state) {
            switch (state) {
                case State::WAIT_N:
                    return 0x22;

                case State::WAIT_E:
                    return 0x14;

                case State::GO_E:
                    return 0x0C;

                case State::GO_N:
                    return 0x21;
            }

            return 0;
        }

        void updateGoNState(int input) {
            switch (input) {
                case 0:
                    currentState = State::GO_N;
                    break;

                case 1:
                    currentState = State::WAIT_N;
                    break;

                case 2:
                    currentState = State::GO_N;
                    break;

                case 3:
                    currentState = State::WAIT_N;
                    break;
            }
        }

        void updateGoEState(int input) {
            switch (input) {
                case 0:
                case 1:
                    currentState = State::GO_E;
                    break;

                case 2:
                case 3:
                    currentState = State::WAIT_E;
                    break;
            }
        }

        void updateWaitNState(int input) {
            currentState = State::GO_E;
        }

        void updateWaitEState(int input) {
            currentState = State::GO_N;
        }
    };

}


#endif //UNTITLED6_SEMIOOPSTATECONTEXT_H
