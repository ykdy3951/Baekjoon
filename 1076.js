const ps = (function (process) {
    const readline = require("readline");
  
    const rl = readline.createInterface({
      input: process.stdin,
      output: process.stdout,
    });
  
    let lines = [];
    let cursor = 0;
  
    rl.on("line", function (line) {
      lines.push(line);
    });
  
    return {
      main(f) {
        f()
          .catch((err) => {
            console.error(err);
            process.exit(1);
          })
          .finally(() => {
            rl.close();
          });
      },
      use(name, f) {
        this[name] = f;
      },
      readLine: async function readLine() {
        return new Promise((resolve) => {
          if (cursor < lines.length) {
            resolve(lines[cursor++]);
          } else {
            setTimeout(() =>
              readLine().then((line) => {
                resolve(line);
              })
            );
          }
        });
      },
      async readArrayLine() {
        const line = await this.readLine();
        return line.split(/\s/).map((t) => parseInt(t));
      },
      write(data) {
        process.stdout.write(data + "");
      },
      writeLine(data) {
        process.stdout.write((data === undefined ? "" : data) + "\n");
      },
      range(start, end, step = 1) {
        if (end === undefined) {
          end = start;
          start = 0;
        }
        return {
          [Symbol.iterator]: function* () {
            for (let i = start; i < end; i += step) {
              yield i;
            }
          },
        };
      },
    };
  })(process);

const dict = {
    "black": [0, 1],
    "brown": [1, 10],
    "red" :	[2,	100],
    "orange" : [3, 1000],
    "yellow" : [4, 10000],
    "green" : [5, 100000],
    "blue" : [6, 1000000],
    "violet" : [7, 10000000],
    "grey" : [8, 100000000],
    "white" : [9, 1000000000],
};

ps.main(async () => {
    const a = await ps.readLine();
    const b = await ps.readLine();
    const c = await ps.readLine();
    
    ps.writeLine((dict[a][0] * 10 + dict[b][0]) * dict[c][1]);
});