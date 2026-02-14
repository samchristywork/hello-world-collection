set terminal pngcairo size 400,200
set output "build/hello.png"
unset border
unset tics
unset key
set label "Hello, World!" at screen 0.5,0.5 center font "Sans,24"
plot [0:1][0:1] NaN
