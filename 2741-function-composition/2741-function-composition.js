/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
        let cx = x;
        for (let i = functions.length-1; i >= 0; i--) {
            const fx = functions[i];
            cx = fx(cx)
        }
        

        return cx;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */