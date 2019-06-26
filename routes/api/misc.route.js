const express = require('express')

const router =express.Router();
const addon = require('../../build/Release/addon');

router.get('/code/:num',(req,res,next)=>{

    try {
    let number = 1 ;
    if(req.params.num)
        number = parseInt(req.params.num);

        console.log(parseInt(number))
    var result = addon.add(number)

    res.status(200).json({result:result});
    }catch(err){
        console.log(err);
        next({
            status: 500,
            message: err
        });
    }
  });




module.exports = router;