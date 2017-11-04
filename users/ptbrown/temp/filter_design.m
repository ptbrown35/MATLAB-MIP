%% fitler design stuff

fs = 200;
fc = fs/2;
wc = 2*pi*fc;

Fs = tf([0 wc], [1 wc])
bode(Fs)

Ts = 1/200;
Fz = c2d(Fs, Ts, 'tustin')