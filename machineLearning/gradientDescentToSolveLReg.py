from numpy import genfromtxt
import matplotlib.pyplot as plt

def plot2d_scatter(X,Y):
    plt.scatter(X,Y)
    plt.xlabel("X")
    plt.ylabel("Y")
    plt.show()

def h(x,theta0,theta1):
    return theta0 + theta1*x

def cost_function(thetas,point):
    error = 0
    costHistory = []
    N = float(len(point))
    for i in range(int(N)):
        costHistory.append((h(point[:,0][i],thetas[0],thetas[1]) - point[:,1][i]))
        error += (h(point[:,0][i],thetas[0],thetas[1]) - point[:,1][i])**2
    return error/(2*N)

def plot_cost_function(point):
    j_theta = []
    thetas = [i for i in range(-10,10)]
    for theta in thetas:
        j_theta.append(cost_function([theta,theta],point))
    plt.plot(j_theta,thetas)
    plt.xlabel("Cost")
    plt.ylabel("Y")
    plt.show()


def gradient(starting_theta0,starting_theta1,iteration,point,learning_rate):
    theta0 = starting_theta0
    theta1 = starting_theta1
    N = float(len(point))
    for j in range(iteration):
        gradient_theta0 = 0
        gradient_theta1 = 0
        for i in range(len(point)):
            gradient_theta0 += h(point[:,0][i],theta0,theta1)- point[:,1][i]
            gradient_theta1 += (h(point[:,0][i],theta0,theta1) - point[:,1][i]) * point[:,0][i]
        theta0 -= learning_rate*((1/N)*gradient_theta0)
        theta1 -= learning_rate*((1/N)*gradient_theta1)
    return [theta0,theta1]

if __name__ == '__main__':
    data = genfromtxt("data.csv",delimiter=",")
    #plot2d_scatter(data[:,0],data[:,1])
    #plot_cost_function(data)
    t0,t1 = gradient(0,0,1000,data,0.0001)
    print t0,t1, cost_function([t0,t1],data)


