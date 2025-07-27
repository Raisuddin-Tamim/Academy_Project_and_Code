import express from "express";
import { registerInfo } from "../controller/registerController.js";

const router = express.Router();

router.post("/register", registerInfo);

export default router;
