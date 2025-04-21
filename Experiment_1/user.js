const { MongoClient, ServerApiVersion } = require('mongodb'); const uri = 
"mongodb+srv://thakurji009:<password>@thakurji.009.mongodb.net/?retryWrites=true&w=major ity&appName=Pratik"; 
 
client = new MongoClient(uri, { 
  serverApi: { 
    version: ServerApiVersion.v1, 
    strict: true, 
    deprecationErrors: true, 
  } 
}); 
 
const connectDB = async () => { 
  try { 
    console.log("Pinged your deployment. You successfully connected to MongoDB!"); 
  } catch (err) { 
    console.error(err.message); 
    process.exit(1); 
  } 
}; 
 
module.exports = { connectDB, client }; 
 
const bcrypt = require('bcryptjs'); const jwt = require('jsonwebtoken'); const { client } = require('../config/db'); 
 
exports.register = async (req, res) => { 
  const { name, email, password } = req.body; 
 
  try { 
    const db = client.db('auth');     const users = db.collection('users'); 
 
    let user = await users.findOne({ email });     if (user) { 
      return res.status(400).json({ msg: 'User already exists' }); 
    } 
 
    const salt = await bcrypt.genSalt(10); 
    const hashedPassword = await bcrypt.hash(password, salt); 
 
    user = { name, email, password: hashedPassword }; 
    await users.insertOne(user); 
 
    const payload = { user: { id: user._id } }; 
 
    jwt.sign(payload, 'secret', { expiresIn: 360000 }, (err, token) => {       if (err) throw err;       res.json({ token }); 
    }); 
  } catch (err) {     console.error(err.message);     res.status(500).send('Server error'); 
  } 
}; 
 
exports.login = async (req, res) => { 
  const { email, password } = req.body; 
 
  try {     const db = client.db('auth'); 
    const users = db.collection('users'); 
 
    let user = await users.findOne({ email }); 
    if (!user) { 
      return res.status(400).json({ msg: 'Invalid credentials' }); 
    } 
 
    const isMatch = await bcrypt.compare(password, user.password);     if (!isMatch) { 
      return res.status(400).json({ msg: 'Invalid credentials' }); 
    } 
 
    const payload = { user: { id: user._id } }; 
 
    jwt.sign(payload, 'secret', { expiresIn: 360000 }, (err, token) => {       if (err) throw err;       res.json({ token }); 
    }); 
  } catch (err) {     console.error(err.message);     res.status(500).send('Server error'); 
  } 
}; 
 
const mongoose = require('mongoose'); const UserSchema = new mongoose.Schema({   name: {     type: String,     required: true, 
  },   email: {     type: String,     required: true,     unique: true, 
  }, 
  password: {     type: String,     required: true, 
  }, 
}); 
 
module.exports = mongoose.model('User', UserSchema); 