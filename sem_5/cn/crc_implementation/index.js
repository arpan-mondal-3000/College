const divisor = "1011";
const augmentation = "000";
let transmittedCodeword = "";

const performXOR = (a, b) => {
    if (a.length !== b.length) {
        throw new Error("Cannot perform XOR operation!");
    }
    let ans = "";
    for (let i = 0; i < a.length; i++) {
        if (a[i] === b[i]) {
            ans += "0";
        } else {
            ans += "1";
        }
    }
    return ans;
}

const crc_algo = (dataword, check = false) => {
    let dividend = dataword;
    if (!check) {
        dividend = dataword + augmentation;
    }

    // Perform the division
    let intermediate = dividend.slice(0, divisor.length);
    for (let i = 0; i < 3; i++) {
        if (intermediate[0] === "1") {
            const xor = performXOR(intermediate, divisor);
            intermediate = xor.slice(1, xor.length) + dividend[i + 4];
        } else {
            intermediate = intermediate.slice(1, intermediate.length) + dividend[i + 4];
        }
    }
    if (intermediate[0] === "1") {
        const xor = performXOR(intermediate, divisor);
        intermediate = xor.slice(1, xor.length);
    } else {
        intermediate = intermediate.slice(1, intermediate.length);
    }
    if (check) {
        return intermediate;
    }
    const codeword = dataword + intermediate;
    return codeword;
}

const handleDatawordSubmit = () => {
    const inp = document.getElementById("dataword");
    const dataword = inp.value;
    if (!inp.value) {
        return;
    }

    const codeword = crc_algo(dataword);
    inp.value = "";

    // Induce random error(50% chance of error)
    transmittedCodeword = "";
    if (Math.random() < 0.5) {
        console.log("Inducing error!");
        // Induce error
        for (let i = 0; i < codeword.length; i++) {
            // 50% chance of flipping of a bit
            if (Math.random() < 0.5) {
                if (codeword[i] === "1") transmittedCodeword += "0";
                else transmittedCodeword += "1";
            } else transmittedCodeword += codeword[i];
        }
    } else {
        transmittedCodeword = codeword;
    }

    // Show dataword, codeword and transmitted codeword
    const codewordOutput = document.getElementById("view-codeword");
    codewordOutput.innerHTML = `<p><span style="font-weight: bold;">Dataword:</span> ${dataword}</p><p><span style="font-weight: bold;">Generated codeword: </span> ${codeword}</p><p><span style="font-weight: bold;">Transmitted codeword: </span> ${transmittedCodeword}</p>`;
}

const handleErrorDetection = () => {
    if (transmittedCodeword === "") return;
    const syndrome = crc_algo(transmittedCodeword, true);
    const receivedDataword = transmittedCodeword.slice(0, transmittedCodeword.length - 3)
    console.log("Syndrome: ", syndrome);
    if (syndrome === augmentation) {
        console.log("There was no error in transmission.");
        const output = document.getElementById("output");
        output.innerHTML = `<p><span style="font-weight: bold;">Received dataword: </span> ${receivedDataword}</p><p><span style="font-weight: bold;">No error during transmission.</span></p>`;
    } else {
        output.innerHTML = `<p><span style="font-weight: bold;">Received dataword: </span> ${receivedDataword}</p><p><span style="font-weight: bold; color: red;">There was error during transmission!</span></p>`;
    }
}