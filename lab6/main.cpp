#include "RungeKutt.hpp"



int main() {

    std::array<double, 4> col{0, 0.5, 0.5, 1};
    std::array<double, 4> str{1.0/6, 1.0/3, 1.0/3, 1.0/6};
    std::array<std::array<double, 4>, 4> m{std::array<double, 4>{0,0,0,0} , std::array<double, 4>{0.5,0,0,0} , std::array<double, 4>{0,0.5,0,0} , std::array<double, 4>{0,0,1,0} };
    
    const ButcherTable<4> table{col, str, m};

    State initial_st;
    initial_st.t = 0;

    Vec S(6);
    S << 6800e3, 0 , 0 , 0, 7000, 0;
    //std::cout << S[4] << std::endl;
    //S << 1, 2, 3;
    initial_st.state = S;

    std::vector<Vec> solution = explicitRK<4>(initial_st, 6, 100, rightPart, table);

    for (int i = 0; i < solution.size(); ++i) {
        std::cout << solution[i][0] << " " << solution[i][1] << std::endl;
    }
}