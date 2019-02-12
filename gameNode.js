var MATRIX_SIZE = 8;

function Node(bord, onTurn, parent, turn) {
    this.bord = bord || [
        ['E', 'X', 'E', 'X', 'E', 'X', 'E', 'X'],
        ['X', 'E', 'X', 'E', 'X', 'E', 'X', 'E'],
        ['E', 'X', 'E', 'X', 'E', 'O', 'E', 'X'],
        ['E', 'E', 'O', 'E', 'E', 'E', 'E', 'E'],
        ['E', 'E', 'E', 'O', 'E', 'E', 'E', 'E'],
        ['O', 'E', 'E', 'E', 'O', 'E', 'O', 'E'],
        ['E', 'O', 'E', 'O', 'E', 'E', 'E', 'O'],
        ['E', 'E', 'O', 'E', 'O', 'E', 'O', 'E']
    ];
    this.onTurn = onTurn || "X";
    this.parent = parent || {};
    this.turn = turn || {};
    this.children = [];
    this.countX = 12;
    this.countO = 12;
}

Node.prototype.nextBoardState = function(move, onTurn) {
    var newBord = this.bord;
    newBord[move.x][move.y] = onTurn;
    //console.log(newBoard, onTurn);
    return newBord;
}

Node.prototype.getChildren = function() {
    var old = this.bord;
    for (var i = 0; i < MATRIX_SIZE; i++) {
        for (var j = 0; j < MATRIX_SIZE; j++) {

            if (old[i][j] === this.onTurn) {
                this.move(old[i][j], { x: i, y: j });
                // old[i - 1][j - 1] === 'E' ? this.children.push(this.nextBordState({ x: i - 1, y: j - 1 }, 'O')) : 0;
                // old[i - 1][j + 1] === 'E' ? this.children.push(this.nextBordState({ x: i - 1, y: j + 1 }, 'O')) : 0;
                // old[i - 1][j - 1] === 'X' ? this.children.push(this.nextBordState({ x: i - 2, y: j - 2 }, 'O')) && --this.countX : 0;
                // old[i - 1][j - 1] === 'Xx' ? this.children.push(this.nextBordState({ x: i - 2, y: j - 2 }, 'O')) && (this.countX -= 2) : 0;
                // old[i - 1][j + 1] === 'X' ? this.children.push(this.nextBordState({ x: i - 2, y: j + 2 }, 'O')) && --this.countX : 0;
                // old[i - 1][j + 1] === 'Xx' ? this.children.push(this.nextBordState({ x: i - 2, y: j + 2 }, 'O')) && (this.countX -= 2) : 0;
            }
        }
    }
};


Node.prototype.move = function(onTurn, cord) {
    var toSearch = [],
        goingUp = onTurn === "X" ? false : true,
        isKoronovan = onTurn === "Xx" || onTurn === "Oo" ? true : false,
        old = this.bord;

    onTurn === "X" || onTurn === "Xx" ? toSearch.push("O") && toSearch.push("Oo") : toSearch.push("X") && toSearch.push("Xx");

    this.moveRec(toSearch, cord.x, cord.y, goingUp, isKoronovan, old, onTurn);

    // if (isKoronovan) {
    //     while (true) {
    //         if (!couldTakeMore || (goingUp && coord.x === 0) || (!goingUp && coord.x === this.board.length - 1)) {
    //             console.log("end of matrix");
    //             return;
    //         }

    //         if (coord.x === 1 || coord.x === this.board.length - 2) {
    //             console.log("no more moves");
    //             return;
    //         }
    //         if (old[coord.x - 1][coord.y - 1] === toSearch[0] && old[coord.x - 2][coord.y - 2] === "E") {
    //             coord.x = coord.x - 2;
    //             coord.y = coord.y - 2;
    //             this.children.push(this.nextBoardState({ x: coord.x - 1, y: coord.y - 1 }, toSearch[0]));
    //         }

    //         if (old[coord.x - 1][coord.y - 1] === toSearch[1] && old[coord.x - 2][coord.y - 2] === "E") {
    //             this.children.push(this.nextBoardState({ x: coord.x - 1, y: coord.y - 1 }, toSearch[1]));
    //         }
    //         if (old[coord.x - 1][coord.y + 1] === toSearch[0]) {
    //             this.children.push(this.nextBoardState({ x: coord.x - 1, y: coord.y + 1 }, toSearch[0]));
    //         }

    //         if (old[coord.x - 1][coord.y + 1] === toSearch[1]) {
    //             this.children.push(this.nextBoardState({ x: coord.x - 1, y: coord.y + 1 }, toSearch[1]));
    //         }
    //     }
    // }
};

Node.prototype.moveRec = function(toSearch, cordX, cordY, goingUp, isKoronovan, old, onTurn, empty) {
    var empty = empty || falsе;
    if (goingUp) {
        if (cordX === 0 || cordX === 1 || cordY === 0 || cordY === 1 || cordY === old.length - 2 || cordY === old.length - 1) {
            empty && this.children.push(this.nextBoardState({ x: cordX, y: cordY }, onTurn));
            console.log("end going up matrix");
            return;
        }
        if (old[cordX - 1][cordY - 1] === toSearch[0] || old[cordX - 1][cordY - 1] === toSearch[1] && old[cordX - 2][cordY - 2] === "E") {
            cordX -= 2;
            cordY -= 2;
            empty = true;

        }
        if (old[cordX - 1][cordY + 1] === toSearch[0] || old[cordX - 1][cordY + 1] === toSearch[1] && old[cordX - 2][cordY + 2] === "E") {
            cordX -= 2;
            cordY += 2;
            empty = true;

        }
    } else if (!goingUp) {
        if (cordX === old.length - 1 || cordX === old.length - 2 || cordY === 0 || cordY === 1 || cordY === old.length - 2 || cordY === old.length - 1) {
            empty && this.children.push(this.nextBoardState({ x: cordX, y: cordY }, onTurn));
            console.log("end going down matrix");
            return;
        }
        if (old[cordX + 1][cordY - 1] === toSearch[0] || old[cordX + 1][cordY - 1] === toSearch[1] && old[cordX + 2][cordY - 2] === "E") {
            cordX += 2;
            cordY -= 2;
            empty = true;

        }
        if (old[cordX + 1][cordY + 1] === toSearch[0] || old[cordX + 1][cordY + 1] === toSearch[1] && old[cordX + 2][cordY + 2] === "E") {
            cordX += 2;
            cordY += 2;
            empty = true;

        }
    }

    empty && this.moveRec(toSearch, cordX, cordY, goingUp, isKoronovan, old, onTurn, empty);
};

var a = new Node();
a.getChildren();
console.log(a.children);