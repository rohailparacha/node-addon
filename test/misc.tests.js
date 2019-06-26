const expect = require('chai').expect;
const assert = require('chai').assert;
const request = require('supertest');

var root = require('./root');

describe('Misc. Tests',  ()=> {


  it('Calculate factorial', function (done) {
    this.timeout(root.timeout);
    request(root.BASE_URL)
      .get("/code/15")
      .expect(200)
      .end(function (err, res) {
        if (err) console.error(res.body);

        assert.equal(res.body.result,1307674368000); 

        done(err);
      });

  });

  it('Exception: Should fail', function (done) {
    this.timeout(root.timeout);
    
    request(root.BASE_URL)
    .get("/code/4")
      .expect(400)
      .end(function (err, res) {
        if (err) console.error(res.body);

        assert.equal(res.body.result,12); 

        done(err);
      });

  });

});