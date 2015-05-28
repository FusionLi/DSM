clear all;
clc;
close all;
raw_data = load('sin_fs12e6_s0.2_h00.txt');
% raw data
y = raw_data(:,1);
x = linspace(0,12e6/2,length(y));
fft_y = fft(y);
%semilogx(x, abs(fft_y))
%title('FFT diagram')
%xlabel('Log of frequency (Hz)')
%ylabel('FFT value')
count_pos = 0;
count_neg = 0;
for i = 1:length(y)
    if y(i) == 1
        count_pos = count_pos + 1;
    elseif y(i) == 2
        count_neg = count_neg + 1;
    end
end

%figure
%bar([1, -1],[count_pos, count_neg])
%title('Bar diagram between 1 and -1')
%ylabel('Count number #')

width = 0;
count = zeros(1, length(y));
for i = 3:length(y)
    if y(i) == y(i - 1)
        width = width + 1;
    else
        count(i) = width;
        width = 0;
    end
end
count = count(count ~= 0);

count_pos = zeros(1, length(count));
count_neg = zeros(1, length(count));
for i = 1:length(count)
    if rem(i,2) == 0
        count_pos(i) = count(i);
    else
        count_neg(i) = count(i);
    end
end
count_pos = count_pos(count_pos ~= 0);
count_neg = count_neg(count_neg ~= 0);

dlmwrite('count_pos.txt',count_pos','\n');
dlmwrite('count_neg.txt',count_neg','\n');

stat_pos = load('stat_pos.txt');
width_pos = stat_pos(:,1);
count_pos = stat_pos(:,2);
%bar(width_pos, count_pos)
%figure
stat_neg = load('stat_neg.txt');
width_neg = stat_neg(:,1);
count_neg = stat_neg(:,2);
%bar(width_neg, count_neg)
bar([width_pos; -width_neg],[count_pos; count_neg])


