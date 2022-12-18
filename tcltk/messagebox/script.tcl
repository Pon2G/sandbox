frame .f0
frame .f1

button .b1 -text "Hello World" -command {puts "Hello World"}
button .b2 -text "Call proc" -command {testproc}
pack .b1 .b2 -in .f0 -fill x

listbox .lb -yscrollcommand ".s1 set" -xscrollcommand ".s2 set"
scrollbar .s1 -orient vertical -command ".lb yview"
scrollbar .s2 -orient horizontal -command ".lb xview"
grid .lb -in .f1 -row 0 -column 0 -sticky nsew
grid .s1 -in .f1 -row 0 -column 1 -sticky ns
grid .s2 -in .f1 -row 1 -column 0 -sticky ew
grid columnconfigure .f1 0 -weight 1
grid rowconfigure .f1 0 -weight 1
#pack .lb -fill both -in .f1 -side left -expand 1
#pack .s -fill y -in .f1 -side left -expand 1

grid .f0 -row 0 -column 0 -sticky ew
grid .f1 -row 1 -column 0 -sticky nsew
grid columnconfigure . 0 -weight 1
grid rowconfigure . 1 -weight 1
