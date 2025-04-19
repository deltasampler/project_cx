const {execSync} = require("child_process");

const commands = [
    "git clone git@deltasampler:deltasampler/cl_cx.git cl",
    "git clone git@deltasampler:deltasampler/engine_cx.git engine",
    "git clone git@deltasampler:deltasampler/examples.git",
    "git clone git@deltasampler:deltasampler/gl_cx.git gl",
    "git clone git@deltasampler:deltasampler/imgui_cx.git imgui"
];

for (const command of commands) {
    try {
        execSync(command, {stdio: "inherit", shell: true});
    } catch (error) {
        console.error(error.message);
    }
}
