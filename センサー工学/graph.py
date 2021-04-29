import matplotlib.pyplot as plt
import japanize_matplotlib
import numpy as np

def thermistor():
    t = np.linspace(10, 100, 1000)
    r = 1000 / t

    plt.plot(
        r,
        color='black',
        linestyle='--',
        label='サーミスタ'
    )

def thermocouple():
    t = np.linspace(1, 100, 1000)
    r = t ** 1.5 / 20

    plt.plot(
        r,
        color='black',
        linestyle=':',
        label='熱電対'
    )

def ic():
    t = np.linspace(1, 100, 1000)
    r = 100 - t

    plt.plot(
        r,
        color='black',
        label='IC温度センサー'
    )

if __name__ == '__main__':
    plt.rcParams['font.size'] = 20
    ic()
    thermistor()
    thermocouple()

    plt.legend()
    plt.xlabel('温度')
    plt.ylabel('出力')
    plt.xticks([])
    plt.yticks([])
    plt.gca().spines['right'].set_visible(False)
    plt.gca().spines['top'].set_visible(False)
    plt.savefig('img/sensors.eps')