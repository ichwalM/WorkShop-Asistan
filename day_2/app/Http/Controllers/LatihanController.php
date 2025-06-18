<?php

namespace App\Http\Controllers;

use App\Models\User;
use Illuminate\Http\Request;

class LatihanController extends Controller
{
    public function index(Request $request){
        try{
            $data = User::select('id','name','email')
                ->when(isset($request->name), function($query) use ($request) {
                    $query->where('name', 'like', '%' . $request->name . '%');
                })
                ->get();
            return $this->ApiResponse('success brow aman aja', $data);
        }catch(\Throwable $th){
            return $this->ApiResponse($th->getFile(), NULL, 500);
        }
    }
}
