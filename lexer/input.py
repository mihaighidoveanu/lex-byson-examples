import numpy as np

def pso(range,func):
    #preconditions
    assert (isinstance(range,tuple))
    assert (hasattr(func,'__call__'))
    # function body
    nr_agents = 20
    X = np.random.uniform(range[0], range[1], nr_agents)

    

    return func(*X)

def Rossenbrock(x):
    # convert the array to a numpy one
    x = np.asarray(x)
    #preconditions
    assert(len(x.shape) == 1)
    # compute the function
    result = 0
    for i in range(len(x) - 1):
        result += 100 * (x[i + 1] - x[i]**2)**2 + (1 - x[i]**2)
    return result


pso((-3,3),Rossenbrock)
