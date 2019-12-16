<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Http\Requests;
use App\Huelight;
use App\Http\Resources\Huelight as HuelightResource;

class HuelightsController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $huelights = Huelight::All();

        // Return collection of switches as a resource
        return HuelightResource::collection($huelights);
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        //
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {
        $huelight = $request->isMethod('put'/*post*/) ? Huelight::findOrFail($request->id) : new Huelight;
        $huelight->on = $request->input('on');
        $huelight->bri = $request->input('bri');
        $huelight->hue = $request->input('hue');
        $huelight->sat = $request->input('sat');

        if($huelight->save()) {
            return new HuelightResource($huelight);
        }
    }

    /**
     * Display the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function show($id)
    {
        $huelight = Huelight::findOrFail($id);
        return new HuelightResource($huelight);
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function edit($id)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, $id)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        // Get light
        $huelight = Huelight::findOrFail($id);
        if($huelight->delete()) {
            return new HuelightResource($huelight);
        }
    }
}
