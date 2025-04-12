import subprocess

commands = [
    "git clone git@deltasampler:deltasampler/cl_cx.git cl",
    "git clone git@deltasampler:deltasampler/engine_cx.git engine",
    "git clone git@deltasampler:deltasampler/examples.git",
    "git clone git@deltasampler:deltasampler/gl_cx.git gl",
    "git clone git@deltasampler:deltasampler/imgui_cx.git imgui"
];

for command in commands:
    subprocess.run(command, shell=True, check=True)
