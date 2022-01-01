import matplotlib.pyplot as plt
import japanize_matplotlib
import numpy as np

def thermistor():
    t = np.linspace(10, 100, 1000)
    r = 1000 / t

    plt.plot(
        r,
        color='#555555',
        label='サーミスタ',
        linewidth=5
    )

def thermocouple():
    t = np.linspace(1, 100, 1000)
    r = t ** 1.5 / 20

    plt.plot(
        r,
        color='#555555',
        label='熱電対',
        linewidth=5
    )

def ic():
    t = np.linspace(1, 100, 1000)
    r = 100 - t

    plt.plot(
        r,
        color='#555555',
        label='IC温度センサー',
        linewidth=5
    )

def forward():
    t = np.linspace(-10, 0, 1000)
    plt.plot(
        t, -t + 1,
        color='#3c3c3c'
    )

    t = np.linspace(0, 5, 1000)
    r = np.exp(-t)

    plt.plot(
        t, r,
        color='#3c3c3c'
    )

def tmp236():
    t = np.linspace(-40, 150, 1000)
    r = t / 100 + 0.5
    plt.plot(
        t, r,
        color='#ff5555',
        linewidth=2
    )

if __name__ == '__main__':
    plt.rcParams['font.size'] = 20
    plt.rcParams['figure.subplot.bottom'] = 0.2
    plt.rcParams['figure.subplot.left'] = 0.15

    tmp236()

    plt.xlabel('温度 [$^\circ$C]')
    plt.ylabel('出力電圧 [V]')
    plt.xticks([-50, -25, 0, 25, 50, 75, 100, 125, 150])
    plt.yticks([0, 0.5, 1, 1.5, 2])
    plt.xlim([-50, 150])
    plt.ylim([0, 2])
    plt.grid(color='#555555', linewidth=1)
    plt.gca().xaxis.label.set_color('#3c3c3c')
    plt.gca().yaxis.label.set_color('#3c3c3c')
    plt.gca().spines['right'].set_visible(False)
    plt.gca().spines['top'].set_visible(False)
    plt.gca().spines['bottom'].set_color('#3c3c3c')
    plt.gca().spines['left'].set_color('#3c3c3c')
    plt.tick_params(axis='both', colors='#3c3c3c')
    plt.savefig('tmp235.eps', transparent=True)