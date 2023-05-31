/**
 * @param {number} millis
 */
async function sleep(millis) {
  return new Promise((res,rej) => {
    try {
      setTimeout(() => res(5), millis)
    } catch(err) {
      rej(err)
    }
  })
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */