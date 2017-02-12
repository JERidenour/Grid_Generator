clf;

M1 = dlmread('grid_1.txt', '\t');

hold on

plot3(M1(:,1), M1(:,2), M1(:,3), 'r*')

xlabel('X')
ylabel('Y')
zlabel('Z')
view(3)
