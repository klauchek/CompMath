import numpy as np
import matplotlib.pyplot as plt
import math

# u(0,t) = 0, t ∈ (0,T], 
# u(x,0) = I(x)
# Co = tau / h

class Grid():

    def __init__(self, Co):
        self.L = 20
        self.T = 18
        self.h = 0.5
        self.Co = Co
        self.tau = self.h * Co
        self.x = np.arange(0, self.L + self.h/2, self.h)
        self.t = np.arange(0, self.T + self.tau/2, self.tau)
        self.Nt = len(self.t)
        self.Nx = len(self.x)

def angle(grid, u):
    for i in range(grid.Nt - 1):
        for j in range(1, grid.Nx):
            u[i + 1][j] = u[i][j] - (grid.tau / grid.h) * u[i][j] * (u[i][j] - u[i][j - 1])
        u[i + 1][0] = 1
        u[i + 1][grid.Nx - 1] = 0

def LaxWendroff(grid, u):
    for i in range(grid.Nt - 1):
        for j in range(1, grid.Nx - 1):
            u[i + 1][j] = u[i][j] + u[i][j] * 0.5 * (grid.tau / grid.h) * (u[i][j - 1] - u[i][j + 1]) + (u[i][j])**2 * 0.5 * (grid.tau / grid.h)**2 * (u[i][j + 1] - 2 * u[i][j] + u[i][j - 1])

        u[i + 1][0] = 1 #u[i][0] + u[i][0] * 0.5 * (grid.tau / grid.h) * (u[i][grid.Nx - 2] - u[i][1]) + (u[i][0])**2 * 0.5 * (grid.tau / grid.h)**2 * (u[i][1] - 2 * u[i][0] + u[i][grid.Nx - 2])
        u[i + 1][grid.Nx - 1] = 0 #u[i][grid.Nx - 1] + u[i][grid.Nx - 1] * 0.5 * (grid.tau / grid.h) * (u[i][grid.Nx - 2] - u[i][0]) + (u[i][grid.Nx - 1])**2 * 0.5 * (grid.tau / grid.h)**2 * (u[i][0] - 2 * u[i][grid.Nx - 1] + u[i][grid.Nx - 2])
    
def solution(grid, scheme):
    # def I(x, grid):
    #     return math.sin(4 * math.pi * x / grid.L)

    def func(x):
        if x < 13: return 1
        if x >= 13 and x < 14: return -x + 14
        else : return 0

    def I(x, grid):
        return func(x)

    u = np.zeros([grid.Nt, grid.Nx])
    u[0] = [I(x, grid) for x in grid.x]      

    scheme(grid, u)
    return u, grid.x, grid.t


def plot_u(grid, u):
    T_max = 18
    time = 0
    i = 0
    fig, axs = plt.subplots(7)
    while time <= T_max:
        axs[i].plot(grid.x, u[int(time / grid.tau)])
        axs[i].axis([0., grid.L, np.min(u[int(time / grid.tau)]), np.max(u[int(time / grid.tau)])])
        axs[i].set_title('$t=${}'.format(time))
        i += 1
        time += 3
    axs[0].set_title(f'Co = {grid.Co}\n ')
    plt.subplots_adjust(hspace=0.7)
    fig.set_figheight(10)
    fig.set_figwidth(7)

def plot_all():
    grids = [Grid(0.6), Grid(1), Grid(1.01)]
    for gr in grids:
        u, x, t = solution(gr, LaxWendroff)
        plot_u(gr, u)
        plt.show()

def main ():
    plot_all()

if __name__ == "__main__":
    main ()
