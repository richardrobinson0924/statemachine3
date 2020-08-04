#include "ModernStateContext.h"
#include "LegacyStateContext.h"
#include "States.h"
#include <random>
#include "SemiOOPStateContext.h"
#include "nanobench.h"


/**
 * {@code
 * N  |   Name    Lights   Time   In=0    In=1    In=2    In=3
 * -  |  -----    ------   ----   ----   -----   -----   -----
 * 0  |    goN      0x11     30    goN   waitN     goN   waitN
 * 1  |  waitN      0x22     05    goE     goE     goE     goE
 * 2  |    goE      0x0C     30    goE     goE   waitE   waitE
 * 3  |  waitE      0X14     05    goN     goN     goN     goN
 * }
*/
//int main(int argc, const char * argv[]) {
//    auto new_context = Modern::StateContext(new Modern::GoNState());
//    auto old_context = Legacy::StateContext(Legacy::GO_N);
//    auto semi_oop_context = Semi::StateContext(Semi::State::GO_N);
//
//    std::mt19937 gen(0);
//    std::uniform_int_distribution<> distr(0, 3);
//
//
//    for (int i = 0; i < 10'000; ++i) {
//        auto random = distr(gen);
//
//        std::cout << "input = 0x" << random << "\n";
//        std::cout << "new_context  light = 0x" << new_context.light << "\n";
//        std::cout << "old_context  light = 0x" << old_context.light << "\n";
//        std::cout << "semi_context light = 0x" << semi_oop_context.light << "\n";
//        std::cout << "\n";
//
//        new_context.update(random);
//        old_context.update(random);
//        semi_oop_context.update(random);
//    }
//
//    return 0;
//}

int main() {
    auto new_context = Modern::StateContext(new Modern::GoNState());
    auto old_context = Legacy::StateContext(Legacy::GO_N);
    auto semi_oop_context = Semi::StateContext(Semi::State::GO_N);

    std::mt19937 gen(0);
    std::uniform_int_distribution<> distr(0, 3);

    ankerl::nanobench::Bench().run("modern", [&] {
        for (int i = 0; i < 10'000; ++i) {
            const auto random = distr(gen);
            ankerl::nanobench::doNotOptimizeAway(new_context.light);
            new_context.update(random);
        }
    });

    gen.seed(0);

    ankerl::nanobench::Bench().run("old", [&] {
        for (int i = 0; i < 10'000; ++i) {
            const auto random = distr(gen);
            ankerl::nanobench::doNotOptimizeAway(new_context.light);
            old_context.update(random);
        }
    });

    gen.seed(0);

    ankerl::nanobench::Bench().run("semi", [&] {
        for (int i = 0; i < 10'000; ++i) {
            const auto random = distr(gen);
            ankerl::nanobench::doNotOptimizeAway(new_context.light);
            semi_oop_context.update(random);
        }
    });
}
